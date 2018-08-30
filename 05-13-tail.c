#include <stdio.h>
#include <stdlib.h>

#define MAX(x,y) ((x) > (y) ? (x) : (y))

#define MAXSZ 2048

char buf[MAXSZ], *lines[MAXSZ];

int main(int argc, char **argv)
{
	int i = 0, n = 10, c;
	char *writer;

	if (argc > 1 && *argv[1] == '-')
		n = MAX(0, atoi(argv[1] + 1));

	lines[0] = writer = buf;
	while (writer - buf <= MAXSZ && (c = getchar()) != EOF)
	{
		*writer++ = c;
		if (c == '\n')
			lines[++i] = writer;
	}
	*writer = '\0';

	printf("%s", lines[MAX(0, i-n)]);
	
	return 0;
}
