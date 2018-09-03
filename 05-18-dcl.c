#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "j-getch.h"

#define MAXTOK 100

enum { NAME, PARENS, BRACKETS };

void dcl(void);
void dirdcl(void);
int gettoken(void);

int tokentype;
char token[MAXTOK],
	 name[MAXTOK],
	 datatype[MAXTOK],
	 out[1000];

int main(int argc, char **argv)
{
	while (gettoken() != EOF)
	{
		/* First token is datatype */
		strcpy(datatype, token);
		out[0] = '\0';
		dcl();
		if (tokentype != '\n')
		{
			printf("Syntax error\n");
		}
		printf("%s: %s %s\n", name, out, datatype);
	}
	return 0;
}

int gettoken(void)
{
	int c;
	char *p = token;
	while ((c = getch()) == ' ' || c == '\t')
		;
	if (c == '(')
	{
		if ((c = getch()) == ')')
		{
			strcpy(token, "()");
			return tokentype = PARENS;
		}
		else
		{
			ungetch(c);
			return tokentype = '(';
		}
	}
	else if (c == '[')
	{
		for (*p++ = c; (*p++ = getch()) != ']'; )
			;
		*p = '\0';
		return tokentype = BRACKETS;
	}
	else if (isalpha(c))
	{
		for (*p++ = c; isalnum(c = getch()); )
			*p++ = c;
		*p = '\0';
		ungetch(c);
		return tokentype = NAME;
	}
	else
		return tokentype = c;
}

void dcl(void)
{
	int star = 0;
	while (gettoken() == '*')
		star++;

	dirdcl();
	while (star-- > 0)
		strcat(out, " pointer to");
}

void dirdcl(void)
{
	int type;

	if (tokentype == '(') /* ( dcl ) */
	{
		dcl();
		if (tokentype != ')')
			printf("Error: missing ')'\n");
	}
	else if (tokentype == NAME)
		strcpy(name, token);
	else
		printf("Error: expected name or (dcl)\n");

	while ((type = gettoken()) == PARENS ||
			type == BRACKETS)
	{
		if (type == PARENS)
			strcat(out, " function returning");
		else
		{
			strcat(out, " array");
			strcat(out, token);
			strcat(out, " of");
		}
	}
}
