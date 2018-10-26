#include "j-qsort.h"
#include "j-lines.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINES 5000
#define MAXLEN 1000

char *lineptr[MAXLINES], alloc[MAXLINES*MAXLEN];

int numcmp(const char *, const char *);

int main(int argc, char **argv)
{
	int nlines, numeric = 0;

	if (argc > 1 && strcmp(argv[1], "-n") == 0)
		numeric = 1;

	if ((nlines = readlines(lineptr, alloc, MAXLINES, MAXLEN)) >= 0)
	{
		vqsort((void**)lineptr, 0, nlines-1,
				(int (*)(void *, void*))(numeric ? numcmp : strcmp), 1);
		writelines(lineptr, nlines);
		return 0;
	}

	printf("Error: input too big to sort\n");
	return 1;
}

int numcmp(const char *a, const char *b)
{
	return atof(a) - atof(b);
}
