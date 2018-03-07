#include <stdio.h>

int main()
{
  int c, state, len, i, j;
  int hist[255];

  for(i = 0; i < 255; i++)
    hist[i] = 0;

  len = 0;
  while((c = getchar()) != EOF) {
    if(c == ' ' || c == '\t' || c == '\n') {
      if(len > 0) {
        ++hist[len];
      }
      len = 0;
    } else {
      ++len;
    }
  }

  for(i = 0; i < 255; i++) {
    if(hist[i] > 0) {
      printf("%d ", i);
      for(j = 0; j < hist[i]; j++)
        putchar('*');
      printf("\n");
    }
  }
}
