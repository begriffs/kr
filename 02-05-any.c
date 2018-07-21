#include <stdio.h>

int
main()
{
	char haystack[255], needles[255];
	int i, j;

	printf("Haystack: ");
	fgets(haystack, 255, stdin);
	printf("Needles : ");
	fgets(needles, 255, stdin);

	for (i = 0; haystack[i] != '\0'; i++)
	{
		for (j = 0; needles[j] != '\0'; j++)
		{
			if (needles[j] != '\n' && needles[j] == haystack[i])
			{
				printf("%c occurrs at position %d\n", needles[j], i);
				return 1;
			}
		}
	}
	puts("No characters in common.");
}
