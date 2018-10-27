#include <stdio.h>

/* strcat:  concatenate t to end of s; s must be big enough */
void pstrcat(char *s, char *t)
{
	while (*s)
		s++;
	while (*t)
		*s++ = *t++;
	*s = '\0';
}

int main(void)
{
	char s[2048], t[1024];
	printf("s> ");
	fgets(s, sizeof(s), stdin);
	printf("t> ");
	fgets(t, sizeof(t), stdin);
	pstrcat(s, t);
	printf("%s\n", s);
}
