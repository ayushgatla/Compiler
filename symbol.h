#ifndef SYMBOL_H    /*helps so thst declarationd are not duplicated*/
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

extern Symbol symtab[MAX_SYMBOLS];  /*here extern makes sure that double declaration doesnt happen*/
extern int symcount;

void add_symbol(char *name, SymbolType type, int scope);
int lookup_symbol(char *name);

#endif
