#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "j-getch.h"

#define MAXWORD 100

struct key {
	char *word;
	int count;
} keytab[] = {
	{"auto", 0},
	{"break", 0},
	{"case", 0},
	{"char", 0},
	{"const", 0},
	{"continue", 0},
	{"default", 0},
	{"int", 0},
	{"size_t", 0},
	{"unsigned", 0},
	{"void", 0},
	{"volatile", 0},
	{"while", 0}
};

/* A comment with the word volatile to test
 * this program against its own source code
 */

#define NKEYS (sizeof(keytab) / sizeof(keytab[0]))

struct key *binsearch(char *, struct key[], size_t);

int main(void)
{
	int c;
	char word[MAXWORD];
	struct key *k;
	enum pstate s = ST_NORMAL;

	while ((c = getword(word, MAXWORD)) != EOF)
	{
		s = new_state(s, c);
		if (isalpha(*word) && s == ST_NORMAL)
			if ((k = binsearch(word, keytab, NKEYS)) != NULL)
				k->count++;
	}
	for (k = keytab; k < keytab + NKEYS; k++)
		if (k->count > 0)
			printf("%4d %s\n", k->count, k->word);
	return 0;
}

struct key *binsearch(char *word, struct key tab[], size_t n)
{
	int cond;
	struct key *lo = tab, *mid, *hi = &tab[n];

	while (lo < hi)
	{
		mid = lo + (hi-lo) / 2;
		if ((cond = strcmp(word, mid->word)) < 0)
			hi = mid;
		else if (cond > 0)
			lo = mid + 1;
		else
			return mid;
	}
	return NULL;
}
