#include <stdio.h>

int main()
{
  printf("hello, world!\n");
}

/* Notes
 *
 * Using an unknown escape sequence produces
 * warning: unknown escape sequence '\q'
 *
 * It actually compiles without stdio.h:
 * warning: implicitly declaring library function
 *    'printf' with type 'int (const char *, ...)'
 *
 * Missing semicolon kills it
 *
 * Leaving off return value is just a warning
 * warning: type specifier missing, defaults to 'int'
 *
 * Exit code is 0 even without explicit return
 *
 */
