#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXWORD 100

struct tnode
{
	char *word;
	struct linelist *lines;

	struct tnode *left;
	struct tnode *right;
};

struct linelist
{
	int number;
	struct linelist *next;
};

struct tnode *addtree(struct tnode *p, char *w, int line);
struct linelist *addline(struct linelist *lp, int line);
void print(struct tnode *p);
int getword(char *w, int max);

int main(void)
{
	int c, line = 1;
	char word[MAXWORD];
	struct tnode *root = NULL;

	while ((c = getword(word, MAXWORD)) != EOF)
	{
		if (c == '\n')
		{
			puts("Bang!");
			line++;
		}
		root = addtree(root, word, line);
	}

	print(root);
	return 0;
}

struct tnode *addtree(struct tnode *p, char *w, int line)
{
	int cmp;

	if (p == NULL)
	{
		p = (struct tnode*) malloc(sizeof(struct tnode));
		p->word = strdup(w);
		p->lines = addline(NULL, line);
		p->left = p->right = NULL;
	}
	else if ((cmp = strcmp(w, p->word)) == 0)
		p->lines = addline(p->lines, line);
	else if (cmp < 0)
		p->left = addtree(p->left, w, line);
	else /* cmp > 0 */
		p->right = addtree(p->right, w, line);
	return p;
}

struct linelist *addline(struct linelist *lp, int line)
{
	if (lp == NULL)
	{
		lp = (struct linelist*) malloc(sizeof(struct linelist));
		lp->number = line;
		lp->next = NULL;
	}
	else if (line != lp->number)
		lp->next = addline(lp->next, line);

	return lp;
}

void print(struct tnode *p)
{
	struct linelist *lp;

	if (!p)
		return;

	print(p->left);

	printf("%-15s\t", p->word);
	for (lp = p->lines; lp; lp = lp->next)
		printf ("%-4i ", lp->number);
	printf("\n");

	print(p->right);
}

int getword(char *w, int max)
{
	int c;
	while (!isalnum(c = getchar()) && c != EOF)
		;
	if (c != EOF)
		*w++ = c;

	while (--max > 1 && (c = getchar()) != EOF)
	{
		if (!isalnum(c))
			break;
		*w++ = c;
	}
	*w = '\0';
	return c;
}
