#include <stdio.h>

int
main()
{
	int c;
	long n;

	n = 0;
	while ((c = getchar()) != EOF)
	{
		if (c == ' ' || c == '\t' || c == '\n')
		{
			++n;
		}
	}
	printf("Whitespace: %ld\n", n);
}
