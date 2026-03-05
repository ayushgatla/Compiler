#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ast.h"

typedef struct IR {
    char result[32];
    char arg1[32];
    char arg2[32];
    char op[8];
    struct IR *next;
} IR;

IR *ir_head = NULL;
IR *ir_tail = NULL;

void emit(char *result, char *arg1, char *op, char *arg2);
char *generate_expr(AST*);
void emit_args(AST*);
void generate_ir(AST*);
void generate_c();
void print_ir();
char *new_label();

int temp_count = 0;
int label_count = 0;

char *new_temp()
{
    static char buffer[32];
    sprintf(buffer,"t%d",temp_count++);
    return strdup(buffer);
}

char *new_label()
{
    static char buffer[32];
    sprintf(buffer,"L%d",label_count++);
    return strdup(buffer);
}

void emit_args(AST *node)
{
    if(node == NULL) return;
    if(node->type == AST_SEQ)
    {
        emit_args(node->left);
        emit_args(node->right);
    }
    else
    {
        char *arg = generate_expr(node);
        emit("PARAM", arg, "", "");
    }
}

char *generate_expr(AST *node)
{
    if(node->type == AST_NUM)
    {
        char *t = new_temp();
        char value[32];
        sprintf(value,"%d",node->value);
        emit(t,value,"",NULL);
        return t;
    }

    if(node->type == AST_VAR)
        return strdup(node->name);

    if(node->type == AST_ADD ||
       node->type == AST_SUB ||
       node->type == AST_MUL ||
       node->type == AST_DIV ||
       node->type == AST_REM)
    {
        char *left  = generate_expr(node->left);
        char *right = generate_expr(node->right);
        char *t = new_temp();
        char *op;

        if(node->type == AST_ADD) op = "+";
        else if(node->type == AST_SUB) op = "-";
        else if(node->type == AST_MUL) op = "*";
        else if(node->type == AST_DIV) op = "/";
        else op = "%";

        emit(t,left,op,right);
        return t;
    }

    if(node->type == AST_GT ||
       node->type == AST_LT ||
       node->type == AST_GE ||
       node->type == AST_LE ||
       node->type == AST_EQ ||
       node->type == AST_NE)
    {
        char *left  = generate_expr(node->left);
        char *right = generate_expr(node->right);
        char *t = new_temp();
        char *op;

        if(node->type == AST_GT) op = ">";
        else if(node->type == AST_LT) op = "<";
        else if(node->type == AST_GE) op = ">=";
        else if(node->type == AST_LE) op = "<=";
        else if(node->type == AST_EQ) op = "==";
        else op = "!=";

        emit(t,left,op,right);
        return t;
    }

    if(node->type == AST_CALL)
    {
        emit_args(node->left);
        char *temp = new_temp();
        emit(temp, node->name, "CALL", "");
        return temp;
    }

    return NULL;
}

void generate_ir(AST *node)
{
    if(node == NULL)
        return;

    switch(node->type)
    {
        case AST_SEQ:
            generate_ir(node->left);
            generate_ir(node->right);
            break;

        case AST_ASSIGN:
        {
            char *rhs = generate_expr(node->right);
            emit(node->left->name, rhs, "", NULL);
            break;
        }

        case AST_PRINT:
        {
            if(node->left->type == AST_STRING)
            {
                emit("PRINT", node->left->str, "", NULL);
            }
            else
            {
                char *v = generate_expr(node->left);
                if(v != NULL)
                    emit("PRINT", v, "", NULL);
            }
            break;
        }

        case AST_SCAN:
        {
            emit("SCAN", node->left->name, "", NULL);
            break;
        }

        case AST_IF:
        {
            char *cond   = generate_expr(node->left);
            char *L_else = new_label();
            char *L_end  = new_label();

            emit("IF_FALSE", cond, "", L_else);
            generate_ir(node->right->left);
            emit("GOTO", "", "", L_end);
            emit("LABEL", L_else, "", "");

            if(node->right->right)
                generate_ir(node->right->right);

            emit("LABEL", L_end, "", "");
            break;
        }

        case AST_WHILE:
        {
            char *L0 = new_label();
            char *L1 = new_label();

            emit("LABEL", L0, "", "");
            char *cond = generate_expr(node->left);
            emit("IF_FALSE", cond, "", L1);
            generate_ir(node->right);
            emit("GOTO", "", "", L0);
            emit("LABEL", L1, "", "");
            break;
        }

        case AST_FUNC:
        {
            emit("FUNC", node->name, "", "");

            /* emit PARAM_DEF for each parameter */
            AST *p = node->left;
            while(p)
            {
                if(p->type == AST_SEQ)
                {
                    emit("PARAM_DEF", p->left->name, "", "");
                    p = p->right;
                }
                else
                {
                    emit("PARAM_DEF", p->name, "", "");
                    break;
                }
            }

            generate_ir(node->right);
            emit("END_FUNC", "", "", NULL);
            break;
        }

        case AST_RETURN:
        {
            char *t = generate_expr(node->left);
            emit("RETURN", t, "", "");
            break;
        }

        default:
            break;
    }
}

void collect_vars(char vars[100][32], int *count)
{
    IR *t = ir_head;

    while(t)
    {
        /* skip all non-assignment instructions */
        if(strcmp(t->result,"PARAM_DEF")==0 ||
           strcmp(t->result,"PRINT")==0     ||
           strcmp(t->result,"LABEL")==0     ||
           strcmp(t->result,"GOTO")==0      ||
           strcmp(t->result,"IF_FALSE")==0  ||
           strcmp(t->result,"FUNC")==0      ||
           strcmp(t->result,"END_FUNC")==0  ||
           strcmp(t->result,"CALL")==0      ||
           strcmp(t->result,"RETURN")==0    ||
           strcmp(t->result,"PARAM")==0     ||
           strcmp(t->op,"CALL")==0)
        {
            t = t->next;
            continue;
        }

        if(strcmp(t->result,"SCAN")==0)
        {
            int found = 0;
            for(int i=0;i<*count;i++)
                if(strcmp(vars[i],t->arg1)==0)
                    found = 1;
            if(!found)
            {
                strcpy(vars[*count],t->arg1);
                (*count)++;
            }
            t = t->next;
            continue;
        }

        /* collect result variable */
        if(strlen(t->result) && isalpha((unsigned char)t->result[0]))
        {
            int found = 0;
            for(int i=0;i<*count;i++)
                if(strcmp(vars[i],t->result)==0)
                    found = 1;
            if(!found)
            {
                strcpy(vars[*count],t->result);
                (*count)++;
            }
        }

        /* collect arg1 variable */
        if(strlen(t->arg1) && isalpha((unsigned char)t->arg1[0]))
        {
            int found = 0;
            for(int i=0;i<*count;i++)
                if(strcmp(vars[i],t->arg1)==0)
                    found = 1;
            if(!found)
            {
                strcpy(vars[*count],t->arg1);
                (*count)++;
            }
        }

        t = t->next;
    }
}

void generate_c()
{
    FILE *f = fopen("output.c","w");

    if(!f){
        printf("Error creating output.c\n");
        return;
    }

    fprintf(f,"#include <stdio.h>\n\n");

    /* ── PASS 1: generate functions ── */

    IR *t = ir_head;

    while(t)
    {
        if(strcmp(t->result,"FUNC")==0)
        {
            /* build signature from PARAM_DEF instructions */
            char sig[256] = "";
            IR *scan = t->next;

            /* skip to first PARAM_DEF */
            while(scan && strcmp(scan->result,"PARAM_DEF")!=0
                       && strcmp(scan->result,"END_FUNC")!=0)
                scan = scan->next;

            /* collect all PARAM_DEF */
            int first_param = 1;
            while(scan && strcmp(scan->result,"PARAM_DEF")==0)
            {
                if(!first_param) strcat(sig,",");
                strcat(sig,"int ");
                strcat(sig,scan->arg1);
                first_param = 0;
                scan = scan->next;
            }

            fprintf(f,"int %s(%s){\n", t->arg1, sig);

            /* collect local vars (excluding params) */
            /* first gather param names so we can skip them */
            char params[32][32];
            int  pcount = 0;
            IR *ps = t->next;
            while(ps && strcmp(ps->result,"PARAM_DEF")==0)
            {
                strcpy(params[pcount++], ps->arg1);
                ps = ps->next;
            }

            /* collect all vars from whole IR, then filter */
            char vars[100][32];
            int  count = 0;
            collect_vars(vars, &count);

            /* print locals that are not params and not main-scope vars */
            /* we only want vars used inside this function body */
            /* simple approach: collect vars between FUNC..END_FUNC */
            char local_vars[100][32];
            int  local_count = 0;
            IR *body = t->next;
            while(body && strcmp(body->result,"PARAM_DEF")==0)
                body = body->next;

            while(body && strcmp(body->result,"END_FUNC")!=0)
            {
                /* result */
                if(strlen(body->result) && isalpha((unsigned char)body->result[0]) &&
                   strcmp(body->result,"PRINT")!=0   &&
                   strcmp(body->result,"SCAN")!=0    &&
                   strcmp(body->result,"LABEL")!=0   &&
                   strcmp(body->result,"GOTO")!=0    &&
                   strcmp(body->result,"IF_FALSE")!=0&&
                   strcmp(body->result,"RETURN")!=0  &&
                   strcmp(body->result,"PARAM")!=0   &&
                   strcmp(body->op,"CALL")!=0)
                {
                    /* skip if it's a param */
                    int is_param = 0;
                    for(int i=0;i<pcount;i++)
                        if(strcmp(params[i],body->result)==0) is_param=1;

                    if(!is_param)
                    {
                        int found = 0;
                        for(int i=0;i<local_count;i++)
                            if(strcmp(local_vars[i],body->result)==0) found=1;
                        if(!found)
                        {
                            strcpy(local_vars[local_count++], body->result);
                        }
                    }
                }
                body = body->next;
            }

            if(local_count > 0)
            {
                fprintf(f,"int ");
                for(int i=0;i<local_count;i++)
                {
                    if(i>0) fprintf(f,",");
                    fprintf(f,"%s",local_vars[i]);
                }
                fprintf(f,";\n");
            }

            /* advance t past PARAM_DEFs */
            t = t->next;
            while(t && strcmp(t->result,"PARAM_DEF")==0)
                t = t->next;

            /* emit function body */
            while(t && strcmp(t->result,"END_FUNC")!=0)
            {
                if(strcmp(t->result,"PRINT")==0)
                {
                    if(t->arg1[0]=='"')
                        fprintf(f,"printf(\"%%s\\n\", %s);\n",t->arg1);
                    else
                        fprintf(f,"printf(\"%%d\\n\", %s);\n",t->arg1);
                }
                else if(strcmp(t->result,"RETURN")==0)
                {
                    fprintf(f,"return %s;\n",t->arg1);
                }
                else if(strcmp(t->result,"PARAM")==0)
                {
                    /* skip */
                }
                else if(strcmp(t->op,"CALL")==0)
                {
                    char args[256] = "";
                    IR *p = ir_head;
                    while(p && p != t)
                    {
                        if(strcmp(p->result,"PARAM")==0)
                        {
                            if(strlen(args)>0) strcat(args,",");
                            strcat(args,p->arg1);
                        }
                        p = p->next;
                    }
                    fprintf(f,"%s = %s(%s);\n",t->result,t->arg1,args);
                }
                else if(strlen(t->arg2)>0)
                {
                    fprintf(f,"%s = %s %s %s;\n",t->result,t->arg1,t->op,t->arg2);
                }
                else
                {
                    fprintf(f,"%s = %s;\n",t->result,t->arg1);
                }

                t = t->next;
            }

            fprintf(f,"}\n\n");
        }

        if(t) t = t->next;
    }

    /* ── PASS 2: generate main ── */

    t = ir_head;

    fprintf(f,"int main(){\n");

    /* collect main-scope vars only (outside any FUNC..END_FUNC) */
    char main_vars[100][32];
    int  main_count = 0;
    IR *mv = ir_head;
    int in_func = 0;

    while(mv)
    {
        if(strcmp(mv->result,"FUNC")==0)     { in_func=1; mv=mv->next; continue; }
        if(strcmp(mv->result,"END_FUNC")==0) { in_func=0; mv=mv->next; continue; }
        if(in_func) { mv=mv->next; continue; }

        if(strcmp(mv->result,"PARAM_DEF")==0 ||
   strcmp(mv->result,"PRINT")==0     ||
   strcmp(mv->result,"LABEL")==0     ||
   strcmp(mv->result,"GOTO")==0      ||
   strcmp(mv->result,"IF_FALSE")==0  ||
   strcmp(mv->result,"RETURN")==0    ||
   strcmp(mv->result,"PARAM")==0)
{ mv=mv->next; continue; }

if(strcmp(mv->op,"CALL")==0)
{
    int found=0;
    for(int i=0;i<main_count;i++)
        if(strcmp(main_vars[i],mv->result)==0) found=1;
    if(!found) strcpy(main_vars[main_count++],mv->result);
    mv=mv->next; continue;
}

        if(strcmp(mv->result,"SCAN")==0)
        {
            int found=0;
            for(int i=0;i<main_count;i++)
                if(strcmp(main_vars[i],mv->arg1)==0) found=1;
            if(!found) strcpy(main_vars[main_count++],mv->arg1);
            mv=mv->next; continue;
        }

        if(strlen(mv->result) && isalpha((unsigned char)mv->result[0]))
        {
            int found=0;
            for(int i=0;i<main_count;i++)
                if(strcmp(main_vars[i],mv->result)==0) found=1;
            if(!found) strcpy(main_vars[main_count++],mv->result);
        }

        mv=mv->next;
    }

    if(main_count>0)
    {
        fprintf(f,"int ");
        for(int i=0;i<main_count;i++)
        {
            if(i>0) fprintf(f,",");
            fprintf(f,"%s",main_vars[i]);
        }
        fprintf(f,";\n\n");
    }

    while(t)
    {
        /* skip function definitions */
        if(strcmp(t->result,"FUNC")==0)
        {
            while(t && strcmp(t->result,"END_FUNC")!=0)
                t = t->next;
            if(t) t = t->next;
            continue;
        }

        else if(strcmp(t->op,"CALL")==0)
        {
            char args[256] = "";
            IR *p = ir_head;
            while(p && p != t)
            {
                if(strcmp(p->result,"PARAM")==0)
                {
                    if(strlen(args)>0) strcat(args,",");
                    strcat(args,p->arg1);
                }
                p = p->next;
            }
            fprintf(f,"%s = %s(%s);\n",t->result,t->arg1,args);
        }

        else if(strcmp(t->result,"PARAM")==0)
        {
            t = t->next;
            continue;
        }

        else if(strcmp(t->result,"PARAM_DEF")==0)
        {
            t = t->next;
            continue;
        }

        else if(strcmp(t->result,"PRINT")==0)
        {
            if(t->arg1[0]=='"')
                fprintf(f,"printf(\"%%s\\n\", %s);\n",t->arg1);
            else
                fprintf(f,"printf(\"%%d\\n\", %s);\n",t->arg1);
        }

        else if(strcmp(t->result,"SCAN")==0)
        {
            fprintf(f,"scanf(\"%%d\", &%s);\n",t->arg1);
        }

        else if(strcmp(t->result,"LABEL")==0)
        {
            fprintf(f,"%s:\n",t->arg1);
        }

        else if(strcmp(t->result,"GOTO")==0)
        {
            fprintf(f,"goto %s;\n",t->arg2);
        }

        else if(strcmp(t->result,"IF_FALSE")==0)
        {
            fprintf(f,"if(!%s) goto %s;\n",t->arg1,t->arg2);
        }

        else if(strlen(t->arg2)>0)
        {
            fprintf(f,"%s = %s %s %s;\n",t->result,t->arg1,t->op,t->arg2);
        }

        else
        {
            fprintf(f,"%s = %s;\n",t->result,t->arg1);
        }

        t = t->next;
    }

    fprintf(f,"\nreturn 0;\n");
    fprintf(f,"}\n");

    fclose(f);
}

void print_ir()
{
    IR *t = ir_head;

    while(t)
    {
        if(strcmp(t->result,"PRINT")==0)
            printf("PRINT %s\n",t->arg1);

        else if(strcmp(t->result,"SCAN")==0)
            printf("SCAN %s\n",t->arg1);

        else if(strcmp(t->result,"LABEL")==0)
            printf("%s:\n",t->arg1);

        else if(strcmp(t->result,"IF_FALSE")==0)
            printf("IF_FALSE %s GOTO %s\n",t->arg1,t->arg2);

        else if(strcmp(t->result,"GOTO")==0)
            printf("GOTO %s\n",t->arg2);

        else if(strcmp(t->op,"CALL")==0)
            printf("%s = CALL %s\n",t->result,t->arg1);

        else if(strlen(t->arg2)>0)
            printf("%s = %s %s %s\n",t->result,t->arg1,t->op,t->arg2);

        else
            printf("%s = %s\n",t->result,t->arg1);

        t=t->next;
    }
}

void emit(char *result, char *arg1, char *op, char *arg2)
{
    IR *node = malloc(sizeof(IR));

    snprintf(node->result,32,"%s",result ? result : "");
    snprintf(node->arg1,  32,"%s",arg1   ? arg1   : "");
    snprintf(node->arg2,  32,"%s",arg2   ? arg2   : "");
    snprintf(node->op,     8,"%s",op     ? op     : "");

    node->next = NULL;

    if(ir_head == NULL)
        ir_head = ir_tail = node;
    else {
        ir_tail->next = node;
        ir_tail = node;
    }
}
