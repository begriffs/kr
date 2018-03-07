#include <stdio.h>

#define MAXLINE 1000

int getl(char line[], int maxline);
void trim(char line[], int len);

int main()
{
  int len;
  char line[MAXLINE];

  while ((len = getl(line, MAXLINE)) > 0) {
    trim(line, len);
    printf("%s\n", line);
  }

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

void trim(char s[], int i)
{
  --i;
  while(i >= 0 && (s[i] == ' ' || s[i] == '\n')) {
    s[i] = '\0';
    --i;
  }
}
