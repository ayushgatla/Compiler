#ifndef AST_H
#define AST_H
//declaration made for ast.c
typedef enum {
    AST_NUM,
    AST_VAR,
    AST_STRING,
    AST_ADD,
    AST_SUB,
    AST_MUL,
    AST_DIV,
    AST_REM,
    AST_GT,
    AST_LT,
    AST_GE,
    AST_LE,
    AST_EQ,
    AST_NE,
    AST_ASSIGN,
    AST_PRINT,
    AST_SCAN,
    AST_IF,
    AST_WHILE,
    AST_FUNC,
    AST_CALL,
    AST_SEQ,
    AST_RETURN
} NodeType;
//a ast node
typedef struct AST {

    NodeType type;

    struct AST *left;
    struct AST *right;
    struct AST *third;

    int value;
    char *name;
    char *str;

} AST;
//declaration of different functions of ast
AST* new_num(int value);
AST* new_var(char *name);
AST* new_string(char *str);

AST* new_node(NodeType type, AST *left, AST *right);

AST* new_assign(AST *var, AST *expr);
AST* new_print(AST *expr);
AST* new_scan(AST *var);

AST* new_if(AST *cond, AST *then_branch, AST *else_branch);
AST* new_while(AST *cond, AST *body);
AST* new_func(char *name, AST *params, AST *body);
AST* new_call(char *name, AST *args);
AST* new_return(AST *expr);
#endif
