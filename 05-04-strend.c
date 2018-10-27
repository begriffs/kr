#include <stdio.h>

/* does t occur at the end of s? 1 : 0 */
int strend(char *s, char *t)
{
	char *send = s, *tend = t;
	while (*send++)
		;
	while (*tend++)
		;
	while (*--send == *--tend)
	{
		if (tend == t)
			return 1;
		if (send == s)
			break;
	}

	return 0;
}

int main(void)
{
	char s[2048], t[2048];
	printf("s> ");
	fgets(s, sizeof(s), stdin);
	printf("t> ");
	fgets(t, sizeof(t), stdin);
	printf("s ends in t? %d\n", strend(s, t));
}
