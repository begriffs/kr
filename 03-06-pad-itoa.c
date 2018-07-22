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

/*
 * make this atoi work for the minimal 2s complement number regardless of
 * word size as well
 */
void
atoi(int n, char s[], int min_len)
{
	int i = 0, sign = n;

	do
	{
		s[i++] = abs(n % 10) + '0';
	} while ((n /= 10) != 0);

	if (sign < 0)
		s[i++] = '-';

	/* pad the number */
	while (i < min_len)
		s[i++] = ' ';

	s[i] = '\0';
	rev(s, i);
}

int
main()
{
	int i, n[] = {1, 10, 100, 1000, 10000, 100000};
	char buf[255];

	for (i = 0; i < 6; i++)
	{
		atoi(n[i], buf, 6);
		puts(buf);
	}
}
