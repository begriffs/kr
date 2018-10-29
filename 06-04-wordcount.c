#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXWORD 100

struct tnode
{
	char *word;
	int count;

	struct tnode *left;
	struct tnode *right;
};

struct tnode *addtree(struct tnode *p, char *w, int line);

int getword(char *w, int max);
size_t count_nodes(struct tnode *p);
int by_count(const void *a, const void *b);

void flatten(struct tnode *p, struct tnode **arr);

int main(void)
{
	int c, line = 1;
	long n;
	char word[MAXWORD];
	struct tnode *root = NULL;
	struct tnode **flat = NULL;

	while ((c = getword(word, MAXWORD)) != EOF)
	{
		if (c == '\n')
			line++;
		root = addtree(root, word, line);
	}

	n = count_nodes(root);
	flat = (struct tnode**)
		malloc(sizeof(struct tnode*) * n);
	flatten(root, flat);

	qsort(flat, n, sizeof(struct tnode*), by_count);

	while (--n >= 0)
		printf("%-4u\t%s\n", flat[n]->count, flat[n]->word);

	return 0;
}

struct tnode *addtree(struct tnode *p, char *w, int line)
{
	int cmp;

	if (p == NULL)
	{
		p = (struct tnode*) malloc(sizeof(struct tnode));
		p->word = strdup(w);
		p->count = 1;
		p->left = p->right = NULL;
	}
	else if ((cmp = strcmp(w, p->word)) == 0)
		p->count++;
	else if (cmp < 0)
		p->left = addtree(p->left, w, line);
	else /* cmp > 0 */
		p->right = addtree(p->right, w, line);
	return p;
}

size_t count_nodes(struct tnode *p)
{
	if (p == NULL)
		return 0;
	return 1 + count_nodes(p->left) + count_nodes(p->right);
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

void _flatten(struct tnode *p, struct tnode **arr, size_t *idx)
{
	if (p == NULL)
		return;
	arr[(*idx)++] = p;
	_flatten(p->left, arr, idx);
	_flatten(p->right, arr, idx);
}

void flatten(struct tnode *p, struct tnode **arr)
{
	size_t idx = 0;
	_flatten(p, arr, &idx);
}

int by_count(const void *a, const void *b)
{
	return (* (struct tnode **)a)->count - (* (struct tnode **)b)->count;
}
