#include <stdio.h>

/*
 * Returns x with the n bits that begin at position p set to the rightmost n
 * bits of y (leaving the other bits unchanged)
 */
unsigned int
setbits(unsigned int x, int p, int n, unsigned int y)
{
	unsigned int mask, y_end;


	/*
	 * ~0 << 3 1111111111111111111111111000 ~(~0 << 3)
	 * 0000000000000000000000000111
	 */
	y_end = ~(~0 << n) & y;

	/*
	 * ~(~0 << 3) << p-3 0000000000000001110000000000 ~(~(~0 << 3) <<
	 * p-3) 1111111111111110001111111111
	 */
	mask = ~(~(~0 << n) << (p + 1 - n));

	return (x & mask) | (y_end << (p + 1 - n));
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
	int i, j;
	for (i = 0; i < 16; i++)
	{
		for (j = 0; j < 16; j++)
		{
			printb(i);
			putchar(',');
			printb(j);
			putchar('=');
			printb(setbits(i, 2, 2, j));
			putchar('\n');
		}
	}
}
