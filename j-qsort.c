#include "j-qsort.h"
#include <string.h>

void swap(void *v[], int i, int j);

/* sort v[left]..v[right] into increasing order */
void jqsort(char *v[], int left, int right)
{
	int i, last;

	if (left >= right)
		return;

	swap((void**)v, left, (left+right)/2);
	for (last=left, i=left+1; i <= right; i++)
		if (strcmp(v[i], v[left]) < 0)
			swap((void**)v, ++left, i);
	swap((void**)v, left, last);

	jqsort(v, left, last-1);
	jqsort(v, last+1, right);
}

void swap(void *v[], int i, int j)
{
	void *t = v[i];
	v[i] = v[j];
	v[j] = t;
}

void vqsort(void *v[], int left, int right,
            int (*cmp)(void *, void *), int scale)
{
	int i, last;

	if (left >= right)
		return;

	swap(v, left, (left+right)/2);
	for (last=left, i=left+1; i <= right; i++)
		if (scale * (*cmp)(v[i], v[left]) < 0)
			swap(v, ++left, i);
	swap(v, left, last);

	vqsort(v, left, last-1, cmp, scale);
	vqsort(v, last+1, right, cmp, scale);
}
