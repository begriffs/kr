#ifndef __J_SYMBOLS
#define __J_SYMBOLS

struct nlist
{
	struct nlist *next;
	char *name;
	char *defn;
};

struct nlist *lookup(char *name);

struct nlist *install(char *name, char *v);

void undef(char *name);

/*
 * Portably initialize hashtab to all NULLs, since
 * it needn't be bitwise zero on all architectures
 */
void inithash(void);

#endif
