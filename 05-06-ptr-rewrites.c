#include <stdio.h>

int getl(char *s, int lim)
{
	int c;
	char *start = s;

	while (s - start < lim && (c = getchar()) != EOF && c != '\n')
		*s++ = c;
	*s = '\0';
	return s - start;
}

void rev(char *s, int n)
{
	char t;
	char *end;
	for (end = s+n-1; s < end; s++, end--)
	{
		t = *s;
		*s = *end;
		*end = t;
	}
}

#define abs(n) ((n) < 0 ? -(n) : (n))

void atoi(int n, char s[])
{
	int sign = n;
	char *start = s;

	do
	{
		*s++ = abs(n % 10) + '0';
	} while ((n /= 10) != 0);

	if (sign < 0)
		*s++ = '-';

	*s = '\0';
	rev(start, s - start);
}

int main()
{
	int i, n[] = {-2147483648, -20, 10, 0, 2147483647};
	char buf[255];

	for (i = 0; i < 5; i++)
	{
		atoi(n[i], buf);
		puts(buf);
	}
}
