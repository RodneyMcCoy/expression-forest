#ifndef SYMTBL_H
#define SYMTBL_H

struct sym {
    char * name;
    double value;
    struct sym * next;
};

int list_length();
void print_list();
struct sym * sym_lookup(char *);

#endif /* SYMTBL_H */
