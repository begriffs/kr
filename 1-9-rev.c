#include <stdio.h>

#define MAXLINE 1000

int getl(char line[], int maxline);
void rev(char line[], int len);

int
main()
{
	int len;
	char line[MAXLINE];

	while ((len = getl(line, MAXLINE)) > 0)
	{
		rev(line, len);
		printf("%s\n", line);
	}

	return 0;
}

int
getl(char s[], int lim)
{
	int c, i;

	for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i)
	{
		if (i < lim - 1)
			s[i] = c;
	}
	if (i >= lim - 1)
		s[lim - 1] = '\0';
	else if (c == '\n')
		s[i] = '\0';

	return i;
}

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
