#include <stdio.h>
#include <ctype.h>

double atof(char s[]) {
	double val, power;
	int i, sign, exp;

	for (i=0; isspace(s[i]); i++)
		;
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');

	if (s[i] == '.')
		i++;
	for (power = 1.0; isdigit(s[i]); i++)
	{
		val = 10.0 * val + (s[i] - '0');
		power *= 10;
	}
	val = sign * val / power;

	if (s[i] == 'e')
	{
		i++;
		sign = (s[i] == '-') ? -1 : 1;
		if (s[i] == '-')
			i++;
		for (exp = 0; isdigit(s[i]); i++)
			exp = 10 * exp + (s[i] - '0');
		while (exp-- > 0)
		{
			val = (sign == 1)
				? val * 10.0
				: val / 10.0;
		}
	}
	return val;
}

int main(void)
{
	printf("%f %f %f\n",
		atof("10.0"), atof("10.001"), atof("-0.1"));
	printf("%f %f %f\n",
		atof("1.2e1"), atof("11e1"), atof("0.1e-1"));
	printf("%f %f %f\n",
		atof("673e-5"), atof("10e-1"), atof("-2e20"));

	return 0;
}
