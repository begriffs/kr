#include "j-lines.h"
#include <string.h>
#include <stdio.h>

#define MIN(x,y) ((x) < (y) ? (x) : (y))

/* lines over lim in length will be read into multiple chunks */
int getl(char s[], int lim)
{
	int c;
	char *t = s;
	while ((c = getchar()) != EOF && c != '\n' && lim-- > 0)
		*t++ = c;
	*t = '\0';
	return t - s;
}


int readlines(char *lineptr[], char *alloc, int maxlines, int maxlen)
{
	int len, nlines;
	char *p, line[maxlen];
   
	p = alloc;
	
	nlines = 0;
	while ((len = getl(line, maxlen)) > 0)
	{
		if (nlines >= maxlines || (p+len) > alloc+(maxlines*maxlen))
			return -1;
		else
		{
			strcpy(p, line);
			lineptr[nlines++] = p;
			p += len+1;
		}
	}
	return nlines;
}

void writelines(char *lineptr[], int nlines)
{
	int i;
	for (i = 0; i < nlines; i++)
		printf("%s\n", lineptr[i]);
}
