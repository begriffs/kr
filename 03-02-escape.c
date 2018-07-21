#include <stdio.h>

void
escape(char *s, char *t)
{
	int i, j = 0;

	for (i = 0; s[i]; i++)
	{
		switch (s[i])
		{
		case '\t':
			t[j++] = '\\';
			t[j++] = 't';
			break;
		case '\n':
			t[j++] = '\\';
			t[j++] = 'n';
			break;
		default:
			t[j++] = s[i];
		}
	}
	t[j++] = '\0';
}

void
unescape(char *s, char *t)
{
	int i, j = 0, in_escape = 0;

	for (i = 0; s[i]; i++)
	{
		if (in_escape)
		{
			switch (s[i])
			{
			case 't':
				t[j++] = '\t';
				break;
			case 'n':
				t[j++] = '\n';
				break;
			default:
				t[j++] = '\\';
				t[j++] = s[i];
			}
			in_escape = 0;
		}
		else
		{
			if (s[i] == '\\')
				in_escape = 1;
			else
				t[j++] = s[i];
		}
	}
	t[j++] = '\0';
}

int
main()
{
	char temp[255];
	char escaped[] = "fun\\t\\t\\very\\f\\u\\nhello\\n",
		 raw[] = "hi\tthere\nyou\\string\n";

	escape(raw, temp);
	printf("%s [esc]-> %s\n", raw, temp);
	unescape(escaped, temp);
	printf("%s  [un]-> %s\n", escaped, temp);
}
