#include "holberton.h"

/**
 * print_b - print binary
 *
 * @args: args
 * @options: options
 */
void print_b(va_list args, Options options)
{
	int digits[64], i, length, totallen;
	unsigned long int n;

	GET_SIZED(n, options, args, unsigned int);

	/* read digits */
	for (length = 0; n != 0 || (length == 0 && options.precision != 0); length++)
	{
		digits[length] = n & 1;
		n >>= 1;
	}

	totallen = length;
	if (options.precision > length)
		totallen = options.precision;

	pad_before(options, totallen, NULL, 0);
	/* print digits */
	outcr('0', totallen - length);
	for (i = length - 1; i >= 0; i--)
		outc(digits[i] + '0');

	pad_after(options, totallen + 0);
}
