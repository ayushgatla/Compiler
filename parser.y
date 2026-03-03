%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void yyerror(const char *s);
int yylex(void);

typedef struct {
    int isInitialized;
    int isString;
    int num;
    char* str;
    
} var;

var vars[26] = {0};
int tempCount = 0;

char* newTemp() {
    char* temp = malloc(10);
    sprintf(temp, "t%d", tempCount++);
    return temp;
}
int labelCount = 0;

char* newLabel() {
    char* label = malloc(10);
    sprintf(label, "L%d", labelCount++);
    return label;
}

char* IR[1000];
int irIndex = 0;

void emit(char* code) {
    IR[irIndex++] = strdup(code);
}
%}

/* ---------- VALUE TYPES ---------- */
%union {
    int num;
    int id;
    char* str;

    struct {
        int isString;
        int num;
        char* str;
        char* place;  

    } val;
    struct {
    char* L1;
    char* L2;
     } labels;
}

/* ---------- TOKENS ---------- */
%token <num> NUM
%token <id> ID
%token <str> STRING
%token LT GT LE GE EQ NE
%token PRINT SCAN IF ELSE WHILE RETURN
%token PLUS MINUS MUL DIV REM ASSIGN
%token LPAREN RPAREN SEMICOLON

/* ---------- TYPES ---------- */
%type <val> expr term factor
%type <str> LABEL
/* ---------- PRECEDENCE ---------- */
%left PLUS MINUS
%left MUL DIV REM
%left LT GT LE GE EQ NE
%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE

%%

/* ---------- PROGRAM ---------- */
program:
      stmt_list
;

/* ---------- STATEMENTS ---------- */
stmt_list:
      stmt_list stmt
    | stmt
;

/* ---------- STATEMENTS ---------- */
LABEL:
{
    $$ = newLabel();
}
;

stmt:
      ID ASSIGN expr SEMICOLON
       {

	    if(vars[$1].isInitialized) {
		if(vars[$1].isString != $3.isString) {
		    printf("Type error: variable '%c' type mismatch\n", 'a' + $1);
		    exit(1);
		}
	    }

	    vars[$1].isInitialized = 1;

	    if($3.isString) {
		vars[$1].isString = 1;
		vars[$1].str = strdup($3.str);
	    } else {
		vars[$1].isString = 0;
		vars[$1].num = $3.num;
	    }
	    char buffer[100];
		sprintf(buffer, "%c = %s", 'a' + $1, $3.place);
		emit(buffer);
       }

    | ID ASSIGN STRING SEMICOLON
        {
	    if(vars[$1].isInitialized && vars[$1].isString == 0) {
		printf("Type error: variable '%c' was int, cannot assign string\n", 'a' +$1);
		exit(1);
	    }

	    vars[$1].isInitialized = 1;
	    vars[$1].isString = 1;
	    vars[$1].str = strdup($3);
	    char* temp = newTemp();
char buffer1[100];
sprintf(buffer1, "%s = \"%s\"", temp, $3);
emit(buffer1);

char buffer2[100];
sprintf(buffer2, "%c = %s", 'a' + $1, temp);
emit(buffer2);
           }

   | PRINT expr SEMICOLON
{
    char buffer[100];
    sprintf(buffer, "PRINT %s", $2.place);
    emit(buffer);
}

   | PRINT STRING SEMICOLON
{
    char* temp = newTemp();
    char buffer1[100];
    sprintf(buffer1, "%s = \"%s\"", temp, $2);
    emit(buffer1);

    char buffer2[100];
    sprintf(buffer2, "PRINT %s", temp);
    emit(buffer2);
}

	| SCAN ID SEMICOLON
{
    vars[$2].isInitialized = 1;
    vars[$2].isString = 0;   // assume input numeric for now

    char buffer[50];
    sprintf(buffer, "READ %c", 'a' + $2);
    emit(buffer);
}
| IF LPAREN expr RPAREN LABEL stmt %prec LOWER_THAN_ELSE
{
    char buffer[100];

    sprintf(buffer, "ifFalse %s goto %s", $3.place, $5);
    emit(buffer);

    sprintf(buffer, "%s:", $5);
    emit(buffer);
}
| IF LPAREN expr RPAREN LABEL stmt ELSE LABEL stmt
{
    char buffer[100];

    // jump if condition false
    sprintf(buffer, "ifFalse %s goto %s", $3.place, $5);
    emit(buffer);

    // jump over else part
    sprintf(buffer, "goto %s", $8);
    emit(buffer);

    // else label
    sprintf(buffer, "%s:", $5);
    emit(buffer);

    // end label
    sprintf(buffer, "%s:", $8);
    emit(buffer);
}
	
 ;
    
	
	

/* ---------- EXPRESSIONS ---------- */
expr:
      expr PLUS term
        {
            if($1.isString || $3.isString) {
                printf("Type error: cannot add string\n");
                exit(1);
            }
            $$.isString = 0;
		char* temp = newTemp();
		char buffer[100];
		sprintf(buffer, "%s = %s + %s", temp, $1.place, $3.place);
		emit(buffer);

		$$.place = temp;
		$$.isString = 0;
        }

    | expr MINUS term
        {
            if($1.isString || $3.isString) {
                printf("Type error: cannot subtract string\n");
                exit(1);
            }
            $$.isString = 0;
		char* temp = newTemp();
		char buffer[100];
		sprintf(buffer, "%s = %s - %s", temp, $1.place, $3.place);
		emit(buffer);

		$$.place = temp;
		$$.isString = 0;
        }
    | expr GT term
{
    char* temp = newTemp();
    char buffer[100];
    sprintf(buffer, "%s = %s > %s", temp, $1.place, $3.place);
    emit(buffer);

    $$.place = temp;
    $$.isString = 0;
}
| expr LT term
{
    char* temp = newTemp();
    char buffer[100];
    sprintf(buffer, "%s = %s < %s", temp, $1.place, $3.place);
    emit(buffer);

    $$.place = temp;
    $$.isString = 0;
}
| expr GE term
{
    char* temp = newTemp();
    char buffer[100];
    sprintf(buffer, "%s = %s >= %s", temp, $1.place, $3.place);
    emit(buffer);

    $$.place = temp;
    $$.isString = 0;
}
| expr LE term
{
    char* temp = newTemp();
    char buffer[100];
    sprintf(buffer, "%s = %s <= %s", temp, $1.place, $3.place);
    emit(buffer);

    $$.place = temp;
    $$.isString = 0;
}
| expr NE term
{
    char* temp = newTemp();
    char buffer[100];
    sprintf(buffer, "%s = %s != %s", temp, $1.place, $3.place);
    emit(buffer);

    $$.place = temp;
    $$.isString = 0;
}  
| expr EQ term
{
    char* temp = newTemp();
    char buffer[100];
    sprintf(buffer, "%s = %s == %s", temp, $1.place, $3.place);
    emit(buffer);

    $$.place = temp;
    $$.isString = 0;
}  

    | term
        {
            $$ = $1;
        }
;

/* ---------- TERMS ---------- */
term:
      term MUL factor
        {
            if($1.isString || $3.isString) {
                printf("Type error: cannot multiply string\n");
                exit(1);
            }
            $$.isString = 0;
		char* temp = newTemp();
		char buffer[100];
		sprintf(buffer, "%s = %s * %s", temp, $1.place, $3.place);
		emit(buffer);

		$$.place = temp;
		$$.isString = 0;
        }

    | term DIV factor
        {
            if($1.isString || $3.isString) {
                printf("Type error: cannot divide string\n");
                exit(1);
            }
            $$.isString = 0;
	char* temp = newTemp();
	char buffer[100];
	sprintf(buffer, "%s = %s / %s", temp, $1.place, $3.place);
	emit(buffer);

	$$.place = temp;
	$$.isString = 0;
        }
       
  | term REM factor
{
    if($1.isString || $3.isString) {
        printf("Type error: cannot mod string\n");
        exit(1);
    }

    char* temp = newTemp();
    char buffer[100];
    sprintf(buffer, "%s = %s %% %s", temp, $1.place, $3.place);
    emit(buffer);

    $$.place = temp;
    $$.isString = 0;
}  

    | factor
        {
            $$ = $1;
        }
;

/* ---------- FACTORS ---------- */
factor:
      NUM
        {
            $$.isString = 0;
	    $$.num = $1;

		char* temp = newTemp();
		char buffer[100];
		sprintf(buffer, "%s = %d", temp, $1);
		emit(buffer);

		$$.place = temp;
        }

    | ID
        {
         if(!vars[$1].isInitialized) {
		printf("Error: variable '%c' used before initialization\n", 'a' + $1);
		exit(1);
	    }

	    $$.isString = vars[$1].isString;

	    if(vars[$1].isString)
		$$.str = vars[$1].str;
	    else
		$$.num = vars[$1].num;

	    char* temp = newTemp();
	    char buffer[100];

	    sprintf(buffer, "%s = %c", temp, 'a' + $1);
	    emit(buffer);

	    $$.place = temp;
	 }
 
    | LPAREN expr RPAREN
        {
            $$ = $2;
        }
;

%%

void yyerror(const char *s) {
    printf("Syntax error: %s\n", s);
}
int main() {
    printf("Enter program:\n");
    yyparse();

    printf("\nGenerated IR:\n");
    FILE *fp = fopen("output.c", "w");

fprintf(fp, "#include <stdio.h>\n");
fprintf(fp, "int main() {\n");


for(int i = 0; i < 26; i++) {
    if(vars[i].isInitialized)
        fprintf(fp, "int %c;\n", 'a' + i);
}


for(int i = 0; i < tempCount; i++)
    fprintf(fp, "int t%d;\n", i);


for(int i = 0; i < irIndex; i++) {

    // READ
    if(strncmp(IR[i], "READ", 4) == 0) {
        char var;
        sscanf(IR[i], "READ %c", &var);
        fprintf(fp, "scanf(\"%%d\", &%c);\n", var);
    }

    // PRINT
    else if(strncmp(IR[i], "PRINT", 5) == 0) {
        char var[20];
        sscanf(IR[i], "PRINT %s", var);
        fprintf(fp, "printf(\"%%d\\n\", %s);\n", var);
    }

    // ifFalse → convert to valid C
    else if(strncmp(IR[i], "ifFalse", 7) == 0) {
        char cond[20], label[20];
        sscanf(IR[i], "ifFalse %s goto %s", cond, label);
        fprintf(fp, "if (!%s) goto %s;\n", cond, label);
    }

    // goto
    else if(strncmp(IR[i], "goto", 4) == 0) {
        char label[20];
        sscanf(IR[i], "goto %s", label);
        fprintf(fp, "goto %s;\n", label);
    }

    // label (ends with :)
    else if(strchr(IR[i], ':')) {
        fprintf(fp, "%s\n", IR[i]);
    }

    // normal assignment
    else {
        fprintf(fp, "%s;\n", IR[i]);
    }
}

fprintf(fp, "return 0;\n}");
fclose(fp);

printf("\nC code generated in output.c\n");

    return 0;
}
