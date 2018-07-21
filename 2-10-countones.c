#include <stdio.h>

/*
 * This works because i&(i-1) flips the rightmost one bit if it exists. The
 * repetition removes them one at a time. The proof myst be by induction on
 * the position of the one, but I'm having trouble with it, so just writing
 * the function.
 */
int
countones(unsigned int i)
{
	int j;
	for (j = 0; i != 0; j++)
		i &= i - 1;
	return j;
}

int
main()
{
	int i;
	for (i = 0; i < 16; i++)
	{
		printf("%d has %d\n", i, countones(i));
	}
}
