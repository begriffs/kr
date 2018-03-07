#include <stdio.h>

#define MAXLINE 10

int getl(char line[], int maxline);
void copy(char to[], char from[]);

int main()
{
  int len;
  int max;
  char line[MAXLINE];
  char longest[MAXLINE];

  max = 0;
  while ((len = getl(line, MAXLINE)) > 0) {
    if (len > max) {
      max = len;
      copy(longest, line);
    }
  }
  if(max>0)
    printf("%d: %s", max, longest);

  return 0;
}

int getl(char s[], int lim)
{
  int c, i;

  for (i=0; (c=getchar())!=EOF && c!='\n'; ++i) {
    if(i < lim-1)
      s[i] = c;
  }
  if(i >= lim-1)
    s[lim-1] = '\0';
  else if(c == '\n')
    s[i] = '\0';

  return i;
}

void copy(char to[], char from[])
{
  int i;
  i = 0;
  while ((to[i] = from[i]) != '\0')
    ++i;
}
