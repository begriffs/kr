#include <stdio.h>

#define abs(n) ((n) < 0 ? -(n) : (n))

void
atoi(int n, char s[])
{
	static int i;

	if (n/10)
		atoi(n/10, s);
	else
	{
		i = 0;
		if (n < 0)
			s[i++] = '-';
	}
	s[i++] = abs(n % 10) + '0';
	s[i] = '\0';
}

int
main()
{
	int i, n[] = {1, 12, -3, 1000};
	char buf[255];

	for (i = 0; i < 4; i++)
	{
		atoi(n[i], buf);
		puts(buf);
	}
}
