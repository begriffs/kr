#include <stdio.h>

/* find x in sorted v[] */
int
binsearch(int x, int v[], int n)
{
	int lo, hi, mid;

	lo = 0;
	hi = n - 1;
	mid = (lo + hi) / 2;

	while (lo <= hi && x != v[mid])
	{
		if (x < v[mid])
			hi = mid - 1;
		else
			lo = mid + 1;
		mid = (lo + hi) / 2;
	}
	return (x == v[mid]) ? mid : -1;
}

int
main()
{
	int as[] = {1, 3, 5, 7, 9};
	int i;

	for (i = -1; i < 11; i++)
	{
		printf("%d[%d] ", i, binsearch(i, as, 6));
	}
}
