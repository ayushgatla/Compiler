#ifndef SYMBOL_H
#define SYMBOL_H

#define MAX_SYMBOLS 256

typedef enum {
    SYM_VAR,
    SYM_FUNC,
    SYM_PARAM
} SymbolType;

typedef struct {
    char name[32];
    SymbolType type;
    int scope;
} Symbol;

extern Symbol symtab[MAX_SYMBOLS];
extern int symcount;

void add_symbol(char *name, SymbolType type, int scope);
int lookup_symbol(char *name);

#endif
