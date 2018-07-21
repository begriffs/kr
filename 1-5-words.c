#include <stdio.h>

#define IN  0
#define OUT 1

int
main()
{
	int c, state;

	state = IN;
	while ((c = getchar()) != EOF)
	{
		if (c == ' ' || c == '\t' || c == '\n')
		{
			state = OUT;
		}
		else
		{
			if (state == OUT)
			{
				putchar('\n');
				state = IN;
			}
			putchar(c);
		}
	}
}
