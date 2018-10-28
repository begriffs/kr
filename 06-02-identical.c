#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#include "j-getch.h"

#define MAXWORD 100

struct tnode
{
	char *word;
	struct tnode *left;
	struct tnode *right;
};

struct tnode *addtree(struct tnode *p, char *w);
char *printgroups(struct tnode *p, unsigned int N);

int main(int argc, char **argv)
{
	int c;
	unsigned int prefix_len = 6;
	char word[MAXWORD];
	enum pstate s = ST_NORMAL;
	struct tnode *root = NULL;

	if (argc > 1 && (prefix_len = atoi(argv[1])) < 1)
	{
		puts("Argument must be a positive number");
		return 1;
	}

	while ((c = getword(word, MAXWORD)) != EOF)
	{
		s = new_state(s, c);
		if (isalpha(*word) && s == ST_NORMAL && strlen(word) >= prefix_len)
			root = addtree(root, word);
	}

	printgroups(root, prefix_len);
	return 0;
}

struct tnode *addtree(struct tnode *p, char *w)
{
	int cmp;

	if (p == NULL)
	{
		p = (struct tnode*) malloc(sizeof(struct tnode));
		p->word = strdup(w);
		p->left = p->right = NULL;
	}
	else 
	{
		if ((cmp = strcmp(w, p->word)) < 0)
			p->left = addtree(p->left, w);
		else if (cmp > 0)
			p->right = addtree(p->right, w);
	}
	return p;
}

char *printgroups(struct tnode *p, unsigned int N)
{
	char *leftmax;

	if (!p)
		return NULL;

	leftmax = printgroups(p->left, N);
	if (leftmax && strncmp(leftmax, p->word, N) != 0)
		puts("------");
	puts(p->word);
	if (p->right && strncmp(p->right->word, p->word, N) != 0)
		puts("------");
	printgroups(p->right, N);

	return p->right ? p->right->word : p->word;
}
