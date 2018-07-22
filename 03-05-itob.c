#include <stdio.h>

void
rev(char s[], int n)
{
	int i;
	char t;
	for (i = 0; i < n / 2; ++i)
	{
		t = s[i];
		s[i] = s[n - i - 1];
		s[n - i - 1] = t;
	}
}

#define abs(n) ((n) < 0 ? -(n) : (n))

void
atob(int n, char s[], int b)
{
	int i = 0, sign = n, r;

	do
	{
		r = abs(n % b);
		s[i++] = r + (r > 9 ? ('A'-10) : '0');
	} while ((n /= b) != 0);

	if (sign < 0)
		s[i++] = '-';

	s[i] = '\0';
	rev(s, i);
}

int
main()
{
	int i, n[] = {0, 10, 16, 17, 2147483647};
	char buf[255];

	for (i = 0; i < 5; i++)
	{
		atob(n[i], buf, 10);
		printf("10: %s\n", buf);
		atob(n[i], buf, 16);
		printf("16: %s\n", buf);
		atob(n[i], buf, 2);
		printf("2: %s\n", buf);
	}
}
