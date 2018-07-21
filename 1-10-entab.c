#include <stdio.h>

#define TABSTOP 4

int
main()
{
	int c, col, sp, i;

	sp = col = 0;
	while ((c = getchar()) != EOF)
	{
		if (c == ' ')
		{
			++sp;
		}
		else
		{
			for (i = 0; i < sp / TABSTOP; ++i)
				putchar('\t');
			for (i = 0; i < sp % TABSTOP; ++i)
				putchar(' ');
			sp = 0;
			putchar(c);
		}
	}

	return 0;
}
