#include "j-qsort.h"
#include "j-lines.h"
#include <stdio.h>

#define MAXLINES 5000
#define MAXLEN 1000

char *lineptr[MAXLINES], alloc[MAXLINES*MAXLEN];

int main(void)
{
	int nlines;

	if ((nlines = readlines(lineptr, alloc, MAXLINES, MAXLEN)) >= 0)
	{
		qsort(lineptr, 0, nlines-1);
		writelines(lineptr, nlines);
		return 0;
	}

	printf("Error: input too big to sort\n");
	return 1;
}
