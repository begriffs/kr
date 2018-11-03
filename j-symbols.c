#include <stdlib.h>
#include <string.h>

#include "j-symbols.h"

#define HASHSZ 101

static struct nlist *hashtab[HASHSZ];

unsigned hash(char *s)
{
	unsigned hashval;

	for (hashval = 0; *s != '\0'; s++)
		hashval = *s + 31 * hashval;
	return hashval % HASHSZ;
}

struct nlist *lookup(char *name)
{
	struct nlist* np;
	for (np = hashtab[hash(name)]; np; np = np->next)
		if (strcmp(name, np->name) == 0)
			return np;
	return NULL;
}

struct nlist *install(char *name, char *v)
{
	struct nlist *np;
	unsigned h;

	if ((np = lookup(name)) == NULL)
	{
		np = malloc(sizeof(*np));
		if (np == NULL || (np->name = strdup(name)) == NULL)
			return NULL;
		h = hash(name);
		np->next = hashtab[h];
		hashtab[h] = np;
	} else
		free(np->defn);

	if ((np->defn = strdup(v)) == NULL)
		return NULL;

	return np;
}

void undef(char *name)
{
	struct nlist *np, *prev;
	unsigned h = hash(name);
	if ((np = hashtab[h]) == NULL)
		return;
	for (prev = NULL; np; np = np->next, prev = np)
	{
		if (strcmp(name, np->name) == 0)
		{
			if (prev == NULL)
				hashtab[h] = np->next;
			else
				prev->next = np->next;
			free(np->name);
			free(np->defn);
			free(np);
			break;
		}
	}
}

void inithash(void)
{
	int i;
	for (i = 0; i < HASHSZ; i++)
		hashtab[i] = NULL;
}
