#include <stdio.h>

#define MAXLEN 15

void printn(char s[], int n);
void shift_back(char s[], int n);
int find_prev_space(char s[], int n);

int
main()
{
	/* this is a raw buffer, no \0 at the end */
	char buf[MAXLEN];

	int c, at;

	at = 0;
	while ((c = getchar()) != EOF)
	{
		buf[at] = c;
		if (c == '\n')
		{
			printn(buf, at);
			at = 0;
		}
		else if (++at >= MAXLEN - 1)
		{
			at = find_prev_space(buf, at);
			printn(buf, at);
			shift_back(buf, at);
			at = MAXLEN - at - 1;
		}
	}

	return 0;
}

void
printn(char s[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		putchar(s[i]);
	if (n > 0)
		putchar('\n');
}

void
shift_back(char s[], int n)
{
	int i = n, j = 0;

	for (i = n; i < MAXLEN; i++)
		s[j++] = s[i];
}

int
find_prev_space(char s[], int n)
{
	int original = n;
	while (n > 0 && s[n] != ' ')
		--n;
	if (n == 0)
	{
		/* no spaces, no change */
		return original;
	}
	return n + 1;
}
