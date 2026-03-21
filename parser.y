%{
#include <stdio.h>
#include <stdlib.h>
#include "symbol.h"
#include <string.h>
#include "ast.h"

AST *root;
int current_scope = 0;
void yyerror(const char *s);
int yylex(void);

%}

//variable types
%union {
    int num;
    char* str;
    AST *node;
}

//tockens
%token <num> NUM

%token <str> STRING
%token LT GT LE GE EQ NE
%token PRINT SCAN IF ELSE WHILE RETURN
%token PLUS MINUS MUL DIV REM ASSIGN
%token LPAREN RPAREN SEMICOLON
%token LBRACE RBRACE
%token FUNC COMMA
%token <str> ID


//TYPES
%type <node> program stmt stmt_list expr term factor 
%type <node> param_list arg_list
%type <node> top_list function top
%type <node> matched_stmt unmatched_stmt

//precedence
%left LT GT LE GE EQ NE
%left PLUS MINUS
%left MUL DIV REM



%%

//program order
program
    : top_list
        {
            root = $1;  /*final ast stored in root(redsult of $1)*/
        }
;
top_list:
      top_list top
        { $$ = new_node(AST_SEQ,$1,$2); }
    | top
        { $$ = $1; }
;
top:
      stmt
    | function
;
function:
    FUNC ID LPAREN param_list RPAREN LBRACE stmt_list RBRACE		/*func add(a,b) {
									   return a+b;
									}*/
{
    if(lookup_symbol($2) == -1)
        add_symbol($2, SYM_FUNC, 0);

    $$ = new_func($2,$4,$7);  /*$2 here is function name , $4 is parameters, $7 is body*/ 
}
;
//statements (production rules)
stmt_list
    : stmt
        { $$ = $1; }
    | stmt_list stmt
        { $$ = new_node(AST_SEQ,$1,$2); }
    ;

stmt
    : matched_stmt     /*solves dangling else problem*/
    | unmatched_stmt	/*matched for if else and unmatched for if only*/
    ;
    
matched_stmt
    : IF LPAREN expr RPAREN matched_stmt ELSE matched_stmt
        { $$ = new_if($3,$5,$7); }
    | ID ASSIGN expr SEMICOLON
        { 
        if(lookup_symbol($1) == -1)              // for semantic analysis we use lookup
        add_symbol($1, SYM_VAR, current_scope);
        $$ = new_assign(new_var($1),$3); 
        }
    | PRINT expr SEMICOLON
        { $$ = new_print($2); }
    | PRINT STRING SEMICOLON
        { $$ = new_print(new_string($2)); }
   | SCAN ID SEMICOLON
    {
        if(lookup_symbol($2) == -1)
            add_symbol($2, SYM_VAR, current_scope);
        $$ = new_scan(new_var($2));
    }
    | WHILE LPAREN expr RPAREN matched_stmt
        { $$ = new_while($3,$5); }
    | LBRACE stmt_list RBRACE
        { $$ = $2; }
    | RETURN expr SEMICOLON
        { $$ = new_return($2); }
    ;

unmatched_stmt
    : IF LPAREN expr RPAREN stmt
        { $$ = new_if($3,$5,NULL); }

    | IF LPAREN expr RPAREN matched_stmt ELSE unmatched_stmt
        { $$ = new_if($3,$5,$7); }
    ;
    
//expressions
expr:
      expr PLUS term 
      { 
      $$ = new_node(AST_ADD, $1, $3); //creates a new node of type AST_ADD
      }
      
      
    | expr MINUS term 
    { 
    $$ = new_node(AST_SUB, $1, $3); 
    }
    | expr GT term { $$ = new_node(AST_GT, $1, $3); }
    | expr LT term { $$ = new_node(AST_LT, $1, $3); }
    | expr GE term { $$ = new_node(AST_GE, $1, $3); }
    | expr LE term { $$ = new_node(AST_LE, $1, $3); }
    | expr EQ term { $$ = new_node(AST_EQ, $1, $3); }
    | expr NE term { $$ = new_node(AST_NE, $1, $3); }
    | term { $$ = $1; }
;

//arithmatic terms
term:
      term MUL factor
        {
             $$ = new_node(AST_MUL, $1, $3);
        }

    | term DIV factor
        {
            $$ = new_node(AST_DIV, $1, $3);
        }
       
  | term REM factor
	{
	    $$ = new_node(AST_REM, $1, $3);
	}  

    | factor
        {
            $$ = $1;
        }
;

//factors
factor:
      NUM
        {
            $$ = new_num($1);
        }

    | ID
        {
             if(lookup_symbol($1) == -1)   /*if non decalred variables gets accesed then error*/
	    {
		printf("Semantic Error: variable %s not declared\n",$1);
		exit(1);
	    }
            $$ = new_var($1);
	}
 
    | LPAREN expr RPAREN
        {
            $$ = $2;
        }
     | ID LPAREN arg_list RPAREN
        {
    if(lookup_symbol($1) == -1)
    {
        printf("Semantic Error: function %s not declared\n",$1);
        exit(1);
    }

    $$ = new_call($1,$3);
}
;
param_list:
    ID   						/*for only one param*/
        { 
	    add_symbol($1, SYM_PARAM, current_scope+1);
	    $$ = new_var($1);
        } 
        
    | param_list COMMA ID				/*for only multple param*/ 
    
    {
    add_symbol($3, SYM_PARAM, current_scope+1);
    $$ = new_node(AST_SEQ,$1,new_var($3));
    }
    |      { $$ = NULL; }
;

arg_list:
      expr               { $$ = $1; }
    | arg_list COMMA expr { $$ = new_node(AST_SEQ,$1,$3); }
    |     { $$ = NULL; }
;
%%

void yyerror(const char *s) {       /*error handeling*/
    printf("Syntax error: %s\n", s);
}

void generate_ir(AST *node);       /*genereates intermedite representation*/
void print_ir();
void generate_c();			/*generates output.c*/

int main()
{
    printf("Enter program:\n");

    yyparse();

    if(root == NULL){
        printf("Parsing failed\n");
        return 1;
    }

    generate_ir(root);
    print_ir();
    generate_c();

    printf("\nC code generated in output.c\n");

    return 0;
}
