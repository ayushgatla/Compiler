%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void yyerror(const char *s);
int yylex(void);

typedef struct {
    int isString;
    int num;
    char* str;
} var;

var vars[26] = {0};
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
    } val;
}

/* ---------- TOKENS ---------- */
%token <num> NUM
%token <id> ID
%token <str> STRING


%token PRINT SCAN IF ELSE WHILE RETURN
%token PLUS MINUS MUL DIV REM ASSIGN
%token LPAREN RPAREN SEMICOLON

/* ---------- TYPES ---------- */
%type <val> expr term factor

/* ---------- PRECEDENCE ---------- */
%left PLUS MINUS
%left MUL DIV REM

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
stmt:
      ID ASSIGN expr SEMICOLON
        {
            if($3.isString) {
                vars[$1].isString = 1;
                vars[$1].str = strdup($3.str);
            } else {
                vars[$1].isString = 0;
                vars[$1].num = $3.num;
            }
        }

    | ID ASSIGN STRING SEMICOLON
        {
            vars[$1].isString = 1;
            vars[$1].str = strdup($3);
        }

    | PRINT expr SEMICOLON
        {
            if($2.isString)
                printf("%s\n", $2.str);
            else
                printf("%d\n", $2.num);
        }

    | PRINT STRING SEMICOLON
        {
            printf("%s\n", $2);
        }

	| SCAN ID SEMICOLON
	{
	    char buffer[256];

	    // keep reading until we get a non-empty line or EOF
	    do {
		if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
		    printf("Input error\n");
		    exit(1);
		}
	    } while (buffer[0] == '\n' || buffer[0] == '\0');

	    buffer[strcspn(buffer, "\n")] = '\0';

	    char *endptr;
	    long val = strtol(buffer, &endptr, 10);

	    if (*endptr == '\0') {
		vars[$2].isString = 0;
		vars[$2].num = (int)val;
	    } else {
		vars[$2].isString = 1;
		vars[$2].str = strdup(buffer);
	    }
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
            $$.num = $1.num + $3.num;
        }

    | expr MINUS term
        {
            if($1.isString || $3.isString) {
                printf("Type error: cannot subtract string\n");
                exit(1);
            }
            $$.isString = 0;
            $$.num = $1.num - $3.num;
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
            $$.num = $1.num * $3.num;
        }

    | term DIV factor
        {
            if($1.isString || $3.isString) {
                printf("Type error: cannot divide string\n");
                exit(1);
            }
            $$.isString = 0;
            $$.num = $1.num / $3.num;
        }
       
    | term REM factor
	{
	    if($1.isString || $3.isString) {
		printf("Type error: cannot mod string\n");
		exit(1);
	    }
	    if($3.num == 0) {
		printf("Runtime error: mod by zero\n");
		exit(1);
	    }
	    $$.isString = 0;
	    $$.num = $1.num % $3.num;
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
        }

    | ID
        {
            if(vars[$1].isString) {
                $$.isString = 1;
                $$.str = vars[$1].str;
            } else {
                $$.isString = 0;
                $$.num = vars[$1].num;
            }
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
    return 0;
}
