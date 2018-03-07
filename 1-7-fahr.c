#include <stdio.h>

float f2c(int);

int main ()
{
  float fahr, lower, upper, step;

  lower = 0;
  upper = 300;
  step  = 20;

  printf("%3s %6s\n", "far", "cel");
  fahr = lower;
  while(fahr <= upper) {
    printf("%3.0f %6.1f\n", fahr, f2c(fahr));
    fahr += step;
  }
}

float f2c(int f)
{
  return (5.0/9.0) * (f-32);
}
