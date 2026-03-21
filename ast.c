#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"
//number
AST* new_num(int value)
{
    AST* node = malloc(sizeof(AST));
    node->type = AST_NUM;
    node->value = value;
    node->left = node->right = node->third = NULL;
    return node;
}
//variable
AST* new_var(char *name)
{
    AST* node = malloc(sizeof(AST));
    node->type = AST_VAR;
    node->name = strdup(name);
    node->left = node->right = node->third = NULL;
    return node;
}
//string
AST* new_string(char *str)
{
    AST* node = malloc(sizeof(AST));
    node->type = AST_STRING;
    node->str = strdup(str);
    node->left = node->right = node->third = NULL;
    return node;
}
//new node for sequences
AST* new_node(NodeType type, AST *left, AST *right)
{
    AST* node = malloc(sizeof(AST));
    node->type = type;
    node->left = left;
    node->right = right;
    node->third = NULL;
    return node;
}
//for assignment
AST* new_assign(AST *var, AST *expr)
{
    AST* node = malloc(sizeof(AST));
    node->type = AST_ASSIGN;
    node->left = var;
    node->right = expr;
    node->third = NULL;
    return node;
}
//for printing
AST* new_print(AST *expr)
{
    AST* node = malloc(sizeof(AST));
    node->type = AST_PRINT;
    node->left = expr;
    node->right = node->third = NULL;
    return node;
}
//for input
AST* new_scan(AST *var)
{
    AST* node = malloc(sizeof(AST));
    node->type = AST_SCAN;
    node->left = var;
    node->right = node->third = NULL;
    return node;
}
//if has condition , then , else as its branch here
AST* new_if(AST *cond, AST *then_branch, AST *else_branch)
{
    AST* node = malloc(sizeof(AST));
    node->type = AST_IF;
    node->left = cond;
    node->right = then_branch;
    node->third = else_branch;
    return node;
}
//for while it is condition and body as branches
AST* new_while(AST *cond, AST *body)
{
    AST *node = malloc(sizeof(AST));
    node->type = AST_WHILE;
    node->left = cond;
    node->right = body;
    node->third = NULL;
    return node;
}
//for function it has parameters and body as branches
AST* new_func(char *name, AST *params, AST *body)
{
    AST *node = malloc(sizeof(AST));

    node->type = AST_FUNC;
    node->name = strdup(name);
    node->left = params;
    node->right = body;
    node->third = NULL;

    return node;
}
//function call
AST* new_call(char *name, AST *args)
{
    AST *node = malloc(sizeof(AST));

    node->type = AST_CALL;
    node->name = strdup(name);
    node->left = args;

    return node;
}
//return
AST* new_return(AST *expr)
{
    AST *node = malloc(sizeof(AST));
    node->type = AST_RETURN;
    node->left = expr;
    node->right = NULL;
    return node;
}
