#include "holberton.h"
/**
 * print_d - Print integer
 * @args: arg list
 * @options: format options
 */
void print_d(va_list args, Options options)
{
	char *prefix = NULL;
	int digits[64], length, i, negative, prefixlen = 0, totallen;
	long int n;

	GET_SIZED(n, options, args, int);
	negative = n < 0;
	/* get length and digits */
	for (length = 0; n != 0 || (length == 0 && options.precision != 0); length++)
	{
		if (negative)
			digits[length] = -(n % 10);
		else
			digits[length] = n % 10;
		n = n / 10;
	}

	if (negative)
		prefix = "-";
	else if (options.space)
		prefix = " ";
	else if (options.plus)
		prefix = "+";

	if (prefix)
		prefixlen = 1;

	totallen = length;
	if (totallen < options.precision)
		totallen = options.precision;

	pad_before(options, totallen, prefix, prefixlen);

	outcr('0', totallen - length);
	/* print digits */
	for (i = length - 1; i >= 0; i--)
		outc(digits[i] + '0');

	pad_after(options, totallen + prefixlen);
}
