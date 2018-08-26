#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXOP 100
#define NUMBER '0'

void ungets(char *s);
int getopt(char[]);
void push(double);
double pop(void);
void printtop(void);
void swaptop(void);
void clear(void);

int main(int argc, char** argv)
{
	int type;
	double op2;
	char s[MAXOP];

	while (--argc)
	{
		ungets(" ");
		ungets(*++argv);
		type = getopt(s);
		switch (type)
		{
			case NUMBER:
				push(atof(s));
				break;
			case '+':
				push(pop() + pop());
				break;
			case '*':
				push(pop() * pop());
				break;
			case '-':
				op2 = pop();
				push(pop() - op2);
				break;
			case '/':
				op2 = pop();
				if (op2 != 0.0)
					push(pop() / op2);
				else
					printf("Error: zero divisor\n");
				break;
			case '%':
				op2 = pop();
				if (op2 != 0.0)
					push(fmod(pop(), op2));
				else
					printf("Error: zero divisor\n");
				break;
			case '!':
				printtop();
				break;
			case '~':
				swaptop();
				break;
			case '_':
				clear();
				break;
			case '\n':
				printf("\t%.8g\n", pop());
				break;
			default:
				printf("Error: unknown command %s\n", s);
				break;
		}
	}
	printf("\t%.8g\n", pop());
	return 0;
}

#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

void push(double f)
{
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("Stack full, can't push %g\n", f);
}

double pop(void)
{
	if (sp > 0)
		return val[--sp];
	else
	{
		printf("Error: stack empty\n");
		return 0.0;
	}
}

void printtop(void)
{
	int i;
	double top;
	if ((i = sp) < 2)
		printf("error: less than two vals in stack\n");
	else
	{
		top = val[--i];
		printf("\t( %.8g %.8g )\n", top, val[--i]);
	}
}

void swaptop(void)
{
	double temp;

	if (sp < 2)
		printf("error: less than two vals in stack\n");
	else
	{
		temp = val[sp-1];
		val[sp-1] = val[sp-2];
		val[sp-2] = temp;
	}
}

void clear(void)
{
	sp = 0;
}

#include <ctype.h>

int getch(void);
void ungetch(int);

int getopt(char s[])
{
	int i, c;
	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	i = 0;
	if (!isdigit(c) && c != '.' && c != '-')
		return c;
	if (c == '-')
	{
		if (isdigit(c = getch()) || c == '.')
			s[++i] = c;
		else
		{
			if (c != EOF)
				ungetch(c);
			return '-';
		}
	}
	if (isdigit(c))
		while (isdigit(s[++i] = c = getch()))
			;
	if (c == '.')
		while (isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';
	if (c != EOF)
		ungetch(c);
	return NUMBER;
}

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungets(char *s)
{
	while(*s)
		ungetch(*s++);
}

void ungetch(int c)
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}

