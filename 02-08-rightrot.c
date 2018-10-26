#include <stdio.h>

/* Rotate (not shift) rightward by n bits */
unsigned int
rightrot(unsigned int x, int n)
{
	int s = sizeof(x) * 8;
	return (x >> n) | (x << (s - n));
}

void
printb(unsigned u)
{
	if (u > 1)
		printb(u >> 1);
	if (u & 1)
		putchar('1');
	else
		putchar('0');
}

int
main()
{
	int i;
	for (i = 0; i < 16; i++)
	{
		printb(i);
		printf("\t->\t");
		printb(rightrot(i, 2));
		putchar('\n');
	}
}
