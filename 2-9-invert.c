#include <stdio.h>

/* Returns x with the n bits that begin at position p
   all inverted */
unsigned int
invert(unsigned int x, int p, int n)
{
	/*
	~(~0 << 3) << p-3
	0000000000000001110000000000
	*/

	return x ^ (~(~0 << n) << (p-n));
}

void printb(unsigned u) {
	if (u > 1)
		printb(u >> 1);
	if (u & 1)
		putchar('1');
	else
		putchar('0');
}

int main() {
	int i, j;
	for (i = 0; i < 16; i++) {
		printb(i);
		printf("^=");
		printb(invert(i, 3, 2));
		putchar('\n');
	}
}
