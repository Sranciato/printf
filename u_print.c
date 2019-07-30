#include "holberton.h"
/**
 * print_u - Print unsigned integer
 * @args: arg list
 * @options: format options
 */
void print_u(va_list args, Options options)
{
	int digits[64];
	long int n;
	int length, i, totallen;

	GET_SIZED(n, options, args, unsigned int);
	/* get length and digits */
	for (length = 0; n != 0 || (length == 0 && options.precision != 0); length++)
	{
		digits[length] = n % 10;
		n = n / 10;
	}

	totallen = length;
	if (options.precision > length)
		totallen = options.precision;

	pad_before(options, totallen, NULL, 0);

	/* print digits */
	outcr('0', totallen - length);
	for (i = length - 1; i >= 0; i--)
		outc(digits[i] + '0');

	pad_after(options, totallen);
}
