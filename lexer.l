%{
#include "ast.h"
#include "parser.tab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
%}

%option noyywrap

DIGIT   [0-9]
LETTER  [a-zA-Z]

%%
					/*we have made custom keywords for our languages down below*/
"display"        { return PRINT; }      /*display for print*/
"read"           { return SCAN; }	/*read  for input*/
"if"             { return IF; }
"else"           { return ELSE; }
"while"          { return WHILE; }
"give"           { return RETURN; }    	/*give for return*/
"func"           { return FUNC; }	/*func for function*/

\"[^\"]*\" {
    yylval.str = strdup(yytext);	/* for matching strings */
    return STRING;			/* here yytext matches for string then strdup
    					   stores in memory then yyval.str stores for parser*/
}												

{LETTER}({LETTER}|{DIGIT})* {		/*rule for identofier*/
    yylval.str = strdup(yytext);
    return ID;
}

{DIGIT}+ {				/*rule for digits*/
    yylval.num = atoi(yytext);
    return NUM;				
}
					/*basic tokens asssignment for symbols*/
"+"  { return PLUS; }
"-"  { return MINUS; }
"*"  { return MUL; }
"/"  { return DIV; }
"%"  { return REM; }
"="  { return ASSIGN; }

"("  { return LPAREN; }
")"  { return RPAREN; }
";"  { return SEMICOLON; }
","  { return COMMA; }
">=" { return GE; }
"<=" { return LE; }
"==" { return EQ; }
"!=" { return NE; }
">"  { return GT; }
"<"  { return LT; }
"{"  { return LBRACE; }
"}"  { return RBRACE; }
[ \t\r\n]+ { }

. {
    printf("Lexical error: invalid character '%s'\n", yytext); /*error handeling*/
    exit(1);
}

%%
