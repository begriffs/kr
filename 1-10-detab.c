#include <stdio.h>

#define TABSTOP 4

int
main()
{
	int c, col, delta;

	col = 0;
	while ((c = getchar()) != EOF)
	{
		if (c == '\t')
		{
			delta = TABSTOP - (col % TABSTOP);
			col = col + delta;
			for (; delta > 0; --delta)
				putchar(' ');
		}
		else
		{
			if (c == '\n')
				col = 0;
			else
				++col;
			putchar(c);
		}
	}

	return 0;
}
