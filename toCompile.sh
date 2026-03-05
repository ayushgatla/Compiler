#!/bin/bash
flex lexer.l
bison -d parser.y
gcc lex.yy.c parser.tab.c ast.c ir.c symbol.c -o compiler
