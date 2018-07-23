#include <stdio.h>

/* rightmost occurrence of t in s */
int
strindex(char s[], char t[])
{
	int i, j, k;
	for (i = 0; s[i] != '\0'; i++)
		;
	for (; i >= 0; i--)
	{
		for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
			;
		if (k > 0 && t[k] == '\0')
			return i;
	}
	return -1;
}

int
main ()
{
	char haystack[] = "ishish!";
	printf("%s\tin %s\t(%i)\n", "ish", "ishish", strindex("ishish", "ish"));
	printf("%s\tin %s\t(%i)\n", "ish", "ishish!", strindex("ishish!", "ish"));
	printf("%s\tin %s\t(%i)\n", "foo", "bar", strindex("bar", "foo"));
	printf("%s\tin %s\t(%i)\n", "", "", strindex("", ""));
	printf("%s\tin %s\t(%i)\n", "", "foo", strindex("foo", ""));
	printf("%s\tin %s\t(%i)\n", "fun", "function", strindex("function", "fun"));
}
