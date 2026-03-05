#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbol.h"

Symbol symtab[MAX_SYMBOLS];
int symcount = 0;

void add_symbol(char *name, SymbolType type, int scope)
{
    if(symcount >= MAX_SYMBOLS)
	{
	    printf("Symbol table overflow\n");
	    exit(1);
	}

	strcpy(symtab[symcount].name, name);
	symtab[symcount].type = type;
	symtab[symcount].scope = scope;
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
