#include "holberton.h"
/**
 * print_d - Print integer
 * @args: arg list
 * @options: format options
 */
void print_d(va_list args, Options options)
{
	char *prefix = NULL;
	int digits[64], length, i, negative, prefixlen = 0;
	long int n;

	GET_SIZED(n, options, args, int);
	negative = n < 0;
	/* get length and digits */
	for (length = 0; n != 0 || length == 0; length++)
	{
		if (negative)
			digits[length] = -(n % 10);
		else
			digits[length] = n % 10;
		n = n / 10;
	}
	/* increase length if less than precision */
	for (; length < options.precision; length++)
		digits[length] = 0;

	if (negative)
	{
		prefix = "-";
		prefixlen = 1;
	}
	else if (options.space)
	{
		prefix = " ";
		prefixlen = 1;
	}
	else if (options.plus)
	{
		prefix = "+";
		prefixlen = 1;
	}

	pad_before(options, length, prefix, prefixlen);
	/* print digits */
	for (i = length - 1; i >= 0; i--)
		outc(digits[i] + '0');

	pad_after(options, length + prefixlen);
}
