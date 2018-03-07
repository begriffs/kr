#include <stdio.h>

#define MAXLINE 1000

int getl(char line[], int maxline);

int main()
{
  int len;
  char line[MAXLINE];

  while ((len = getl(line, MAXLINE)) > 0)
    if (len > 80)
      printf("%s", line);

  return 0;
}

int getl(char s[], int lim)
{
  int c, i, j;

  for (i=j=0; (c=getchar())!=EOF && c!='\n'; ++i) {
    if(i < lim-2) {
      s[i] = c;
      ++j;
    }
  }
  if(c == '\n') {
    s[j] = c;
    ++j;
    ++i;
  }
  s[j] = '\0';

  return i;
}
