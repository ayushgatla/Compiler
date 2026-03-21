#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbol.h"

Symbol symtab[MAX_SYMBOLS];  /*stores all variables,functions,parameters*/
int symcount = 0;

void add_symbol(char *name, SymbolType type, int scope) /*adds every symbol to table*/
{
    if(symcount >= MAX_SYMBOLS)
	{
	    printf("symbol table overflow");
	    exit(1);
	}

	strcpy(symtab[symcount].name, name); /*stores identifier*/
	symtab[symcount].type = type;	     /*stores type like var,function,parameter*/
	symtab[symcount].scope = scope;      /*stores scope like global or local*/
	symcount++;
	}

int lookup_symbol(char *name)
{
    for(int i = symcount - 1; i >= 0; i--)
    {
        if(strcmp(symtab[i].name, name) == 0)
            return i;
    }
    return -1;
}
