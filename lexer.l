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

"display"        { return PRINT; }
"read"           { return SCAN; }
"if"             { return IF; }
"else"           { return ELSE; }
"while"          { return WHILE; }
"give"           { return RETURN; }
"func"           { return FUNC; }

\"[^\"]*\" {
    yylval.str = strdup(yytext);
    return STRING;
}

{LETTER}({LETTER}|{DIGIT})* {
    yylval.str = strdup(yytext);
    return ID;
}

{DIGIT}+ {
    yylval.num = atoi(yytext);
    return NUM;
}

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
    printf("Lexical error: invalid character '%s'\n", yytext);
    exit(1);
}

%%
