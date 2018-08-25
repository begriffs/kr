#include "j-qsort.h"
#include <string.h>

/* sort v[left]..v[right] into increasing order */
void qsort(char *v[], int left, int right)
{
	int i, last;
	void swap(char *v[], int i, int j);

	if (left >= right)
		return;

	swap(v, left, (left+right)/2);
	for (last=left, i=left+1; i <= right; i++)
		if (strcmp(v[i], v[left]) < 0)
			swap(v, ++left, i);
	swap(v, left, last);

	qsort(v, left, last-1);
	qsort(v, last+1, right);
}

void swap(char *v[], int i, int j)
{
	char *t = v[i];
	v[i] = v[j];
	v[j] = t;
}
