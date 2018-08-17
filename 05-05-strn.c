#include <stdio.h>

/* copy at most n characters of string t to s
 *
 * return s
 * 
 * Pad with \0's if t has fewer than n characters.
*/
char *pstrncpy(char *s, char *t, int n) 
{
	char *ret = s;
	while (n-- > 0)
	{
		*s++ = *t;
		if (*t)
			t++;
	}
	*s = '\0';
	return ret;
}


/*
concatenate at most n characters of string t to string s

terminate s with '\0'

return s
*/
char *pstrncat(char *s, char *t, int n) 
{
	char *ret = s;
	while (*s)
		s++;
	while (n-- > 0 && *t)
		*s++ = *t++;
	*s = '\0';
	return ret;
}

/*
 * compare at most n characters of string s to string t
 *
 * return <0 if s<t, 0 if s==t, or >0 if s>t
 */
int pstrncmp(char *s, char *t, int n)
{
	while (--n > 0 && *s && *t)
	{
		if (*s != *t)
			return *s - *t;
		s++;
		t++;
	}
	return *s - *t;
}

int main(void)
{
	char s[2048], t[2048];
	printf("s> ");
	gets(s);
	printf("t> ");
	gets(t);
	printf("%d\n", pstrncmp(s, t, 4));
}
