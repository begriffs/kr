#include <stdio.h>
#include <ctype.h>
#include "j-getch.h"

int getfloat(float *f) {
	int c, sign;
	float power;

	while (isspace(c = getch()))
		;
	if (!isdigit(c) && c != EOF &&
	    c != '+' && c != '-' && c != '.')
	{
		ungetch(c);  /* it is not a number */
		return 0;
	}
	sign = (c == '-') ? -1 : 1;
	if (c == '-' || c == '+')
		c = getch();

	for (*f = 0; isdigit(c); c = getch())
		*f = 10 * *f + (c - '0');

	if (c == '.')
		c = getch();

	for (power = 1.0; isdigit(c); c = getch())
	{
		*f = 10 * *f + (c - '0');
		power *= 10;
	}
	*f *= sign / power;

	if (c != EOF)
		ungetch(c);
	return c;
}

int main(void)
{
	float f;
	while (getfloat(&f))
		printf("%f\n", f);
}
