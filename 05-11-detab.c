#include <stdio.h>
#include <stdlib.h>

int tabstops[100];

int main(int argc, char **argv)
{
	int c, col, delta, *ts = tabstops;

	while (*++argv)
		*ts++ = atoi(*argv);
	ts = tabstops;

	col = 0;
	while ((c = getchar()) != EOF)
	{
		if (c == '\t')
		{
			while ((delta = *ts++ - col) <= 0 && ts-tabstops < argc)
				;
			col += delta;
			for (; delta > 0; --delta)
				putchar(' ');
		}
		else
		{
			if (c == '\n')
			{
				ts = tabstops;
				col = 0;
			}
			else
				++col;
			putchar(c);
		}
	}
	return 0;
}
