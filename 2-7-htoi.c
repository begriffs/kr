#include <stdio.h>

int main()
{
	unsigned long value = 0;
	int c, delta;

	while ((c = getchar()) != EOF) {
		if (c >= '0' && c <= '9')
			delta = c - '0';
		else if (c >= 'a' && c <= 'f')
			delta = c - 'a' + 10;
		else if (c != '\n') {
			fprintf(stderr, "Invalid hex digit: %c\n", c);
			return 1;
		}

		if (c != '\n')
			value = 16*value + delta;
	}
	printf("Base-10: %lu\n", value);
}
