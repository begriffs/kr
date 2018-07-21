/*
 * Make an equivalent loop without || or &&
 * 
 * for (i=0; i < lim-1 && (c=getchar()) != '\n' && c != EOF; ++i) s[i] = c;
 */

i = 0;
good = 1;
while (good)
{
	if (i >= lim - 1)
		good = 0;
	else if ((c = getchar()) == '\n')
		good = 0;
	else if (c == EOF)
		good = 0;
	else
	{
		s[i] = c;
		++i;
	}
}
