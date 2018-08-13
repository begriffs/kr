#include <stdio.h>
#include <ctype.h>
#include "j-getch.h"

int getint(int *n)
{
	int c, d, sign;
	while (isspace(c = getch()))
		;
	if (!isdigit(c) && c != EOF && c != '+' && c != '-')
	{
		ungetch(c);  /* it is not a number */
		return 0;
	}
	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-')
	{
		if (!isdigit(d = getch()))
		{
			if (d != EOF)
				ungetch(d);
			ungetch(c);
			return 0;
		}
		c = d;
	}

	for (*n = 0; isdigit(c); c = getch())
		*n = 10 * *n + (c - '0');
	*n *= sign;

	if (c != EOF)
		ungetch(c);
	return c;
}

int main(void)
{
	int i;
	while (getint(&i))
		printf("%d\n", i);
}
