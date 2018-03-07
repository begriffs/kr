#include <stdio.h>

int main ()
{
  float fahr, celcius,
        lower, upper, step;

  lower = 0;
  upper = 300;
  step  = 20;

  printf("%3s %6s\n", "far", "cel");
  fahr = lower;
  while(fahr <= upper) {
    celcius = (5.0/9.0) * (fahr-32.0);
    printf("%3.0f %6.1f\n", fahr, celcius);
    fahr += step;
  }
}
