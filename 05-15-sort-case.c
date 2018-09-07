#include "j-qsort.h"
#include "j-lines.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXLINES 5000
#define MAXLEN 1000

char *lineptr[MAXLINES], alloc[MAXLINES*MAXLEN];

int numcmp(const char *, const char *);
int strcmpi(const char *a, const char *b);
int revcmp(int (*)(void*, void*));

int main(int argc, char **argv)
{
	int nlines, scale = 1;
	char *flags;
	int (*cmp)(const char*, const char*) = strcmp;

	while (*++argv) // skip argv[0]
	{
		if (**argv == '-')
		{
			for (flags = *argv+1; *flags; flags++)
			{
				switch (*flags)
				{
					case 'n':
						cmp = numcmp;
						break;
					case 'r':
						scale = -1;
						break;
					case 'f':
						cmp = strcmpi;
						break;
					default:
						printf("Unknown flag %c\n", *flags);
						break;
				}
			}
		}
	}

	if ((nlines = readlines(lineptr, alloc, MAXLINES, MAXLEN)) >= 0)
	{
		vqsort((void**)lineptr, 0, nlines-1,
				(int (*)(void *, void *))cmp, scale);
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

int strcmpi(const char *a, const char *b)
{
	char upa, upb;
	while (*a && ((upa = toupper(*a)) == (upb = toupper(*b))))
	{
		a++;
		b++;
	}
	return upa - upb;
}
