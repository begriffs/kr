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

enum pstate { NORMAL, STR, STR_ESC,
	COMMENT_IN, COMMENT, COMMENT_OUT };
enum pstate new_state(enum pstate, int);

#define NKEYS (sizeof(keytab) / sizeof(keytab[0]))

int getword(char *, int);
struct key *binsearch(char *, struct key[], size_t);

int main(void)
{
	int c;
	char word[MAXWORD];
	struct key *k;
	enum pstate s = NORMAL;

	while ((c = getword(word, MAXWORD)) != EOF)
	{
		s = new_state(s, c);
		if (isalpha(*word) && s == NORMAL)
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

enum pstate new_state(enum pstate old, int c)
{
	switch (old)
	{
		case NORMAL:
			if (c == '/')
				return COMMENT_IN;
			if (c == '"')
				return STR;
			return NORMAL;
		case STR:
			if (c == '\\')
				return STR_ESC;
			if (c == '"')
				return NORMAL;
			return STR;
		case STR_ESC:
			return STR;
		case COMMENT_IN:
			if (c == '*')
				return COMMENT;
			return NORMAL;
		case COMMENT:
			if (c == '*')
				return COMMENT_OUT;
			return COMMENT;
		case COMMENT_OUT:
			if (c == '/')
				return NORMAL;
			return COMMENT;
		default:
			printf("Invalid state\n");
			return NORMAL;
	}
}

int getword(char *word, int lim)
{
	int c;
	char *w = word;

	while (isspace(c = getch()))
		;
	if (c != EOF)
		*w++ = c;
	if (!isalpha(c))
	{
		*w = '\0';
		return c;
	}
	for (; --lim > 1; w++)
		if (!isalnum(*w = getch()) && *w != '_')
		{
			ungetch(*w);
			break;
		}
	*w = '\0';
	return *word;
}
