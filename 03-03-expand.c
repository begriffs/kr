#include <stdio.h>

void
expand(char s[], char t[])
{
	int i, j;
	char c;

	i = j = 0;
	while ((c = s[i++]) != '\0')
	{
		if (s[i] == '-' && s[i + 1] > c)
		{
			i++;
			while (c < s[i])
				t[j++] = c++;
		}
		else
			t[j++] = c;
	}
	t[j] = '\0';
}

int
main()
{
	char t[255];
	char inputs[8][13] = {
		"a-b-c", "-a", "t-v", "0-9a-j", "-", "", "x-a", "hello0-3a-d-"
	};
	int i;

	for (i = 0; i < 8; i++)
	{
		expand(inputs[i], t);
		printf("%s -> %s\n", inputs[i], t);
	}
}
