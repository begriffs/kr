#ifndef __J_QSORT
#define __J_QSORT

void jqsort(char *v[], int left, int right);

void vqsort(void *v[], int left, int right,
            int (*cmp)(void *, void *));

#endif
