#include <stdio.h>
#include <limits.h>

int
main()
{
	printf("char : %lu\n", sizeof(char));
	printf("short: %lu\n", sizeof(short));
	printf("int  : %lu\n", sizeof(int));
	printf("long : %lu\n", sizeof(long));

	printf("max signed char : %d\n", CHAR_MAX);
	printf("max signed short: %d\n", SHRT_MAX);
	printf("max signed int  : %d\n", INT_MAX);
	printf("max signed long : %ld\n", LONG_MAX);

	printf("max unsigned char : %u\n", UCHAR_MAX);
	printf("max unsigned short: %u\n", USHRT_MAX);
	printf("max unsigned int  : %u\n", UINT_MAX);
	printf("max unsigned long : %lu\n", ULONG_MAX);

	printf("min signed char : %d\n", CHAR_MIN);
	printf("min signed short: %d\n", SHRT_MIN);
	printf("min signed int  : %d\n", INT_MIN);
	printf("min signed long : %ld\n", LONG_MIN);

	return 0;
}
