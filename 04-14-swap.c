#include <stdio.h>

#define swap(t,x,y) { t __tmp; __tmp=x; x=y; y=__tmp; }

int main(int argc, char** argv)
{
	int i = 1, j = 2;
	swap(int, i, j);
	printf("i,j = %d,%d\n", i, j);
	return 0;
}
