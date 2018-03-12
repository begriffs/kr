#include <stdio.h>

int main()
{
	char s[255], baddies[255];
	int i,j=0,k;

	fgets(s, 255, stdin);
	fgets(baddies, 255, stdin);
	
	for (i = j = k = 0; s[i] != '\0'; i++) {
		for (k = 0; baddies[k] != '\0' && s[i] != baddies[k]; k++)
			;
		if (baddies[k] == '\0')
			s[j++] = s[i];
	}
	s[j] = '\0';
	puts(s);
}
