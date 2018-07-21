#include <stdio.h>

int
main()
{
	putchar('?');
	printf("%d | %d\n", getchar() != EOF, EOF);
}
