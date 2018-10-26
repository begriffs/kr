#include <stdio.h>
#include <stdlib.h>

int tabstops[100];

int main(int argc, char **argv)
{
	int c, col, sp, i, *ts = tabstops, remainder;
	(void)argc;

	while (*++argv)
		*ts++ = atoi(*argv);
	ts = tabstops;

	remainder = sp = col = 0;
	while ((c = getchar()) != EOF)
	{
		if (c == ' ')
			++sp;
		else
		{
			while (*ts < sp)
			{
				putchar('\t');
				remainder = sp - *ts;
				ts++;
			}
			for (i = 0; i < remainder; ++i)
				putchar(' ');
			remainder = sp = 0;
			putchar(c);
		}
	}

	return 0;
}
