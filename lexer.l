%{
#include "parser.tab.h"
#include <stdlib.h>
#include <string.h>
%}
%option noyywrap

DIGIT      [0-9]
LETTER     [a-zA-Z]

%%

"display"        { return PRINT; }
"read"           { return SCAN; }
"if"             { return IF; }
"else"           { return ELSE; }
"while"          { return WHILE; }
"give"           { return RETURN; }


\"[^\"]*\"       {
                  yylval.str = strdup(yytext);
                  return STRING;
                 }


{LETTER}       {
                  yylval.id = yytext[0] - 'a';
                  return ID;
               }


{DIGIT}+       {
                  yylval.num = atoi(yytext);
                  return NUM;
               }

"+"            { return PLUS; }
"-"            { return MINUS; }
"*"            { return MUL; }
"/"            { return DIV; }
"%"            { return REM; }
"="            { return ASSIGN; }


"("            { return LPAREN; }
")"            { return RPAREN; }
";"            { return SEMICOLON; }


[ \t\r\n]+     { /* skip */ }


.              {
                  printf("Lexical error: invalid character '%s'\n", yytext);
                  exit(1);
               }

%%


