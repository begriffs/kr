#include "j-getch.h"
#include <stdio.h>
#include <ctype.h>

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}

enum pstate new_state(enum pstate old, int c)
{
	switch (old)
	{
		case ST_NORMAL:
			if (c == '/')
				return ST_COMMENT_IN;
			if (c == '"')
				return ST_STR;
			return ST_NORMAL;
		case ST_STR:
			if (c == '\\')
				return ST_STR_ESC;
			if (c == '"')
				return ST_NORMAL;
			return ST_STR;
		case ST_STR_ESC:
			return ST_STR;
		case ST_COMMENT_IN:
			if (c == '*')
				return ST_COMMENT;
			return ST_NORMAL;
		case ST_COMMENT:
			if (c == '*')
				return ST_COMMENT_OUT;
			return ST_COMMENT;
		case ST_COMMENT_OUT:
			if (c == '/')
				return ST_NORMAL;
			return ST_COMMENT;
		default:
			printf("Invalid state\n");
			return ST_NORMAL;
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
