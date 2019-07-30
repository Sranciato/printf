#include "holberton.h"

/**
 * print_o - print octal
 *
 * @args: args
 * @options: options
 */
void print_o(va_list args, Options options)
{
	int digits[64], i, length, prefixlen = 0, totallen;
	char *prefix = NULL;
	unsigned long int n;

	GET_SIZED(n, options, args, unsigned int);

	if (options.hash && n != 0)
	{
		prefix = "0";
		prefixlen = 1;
	}

	/* read digits */
	for (length = 0; n != 0 || (length == 0 && options.precision != 0); length++)
	{
		digits[length] = n & 7;
		n >>= 3;
	}

	totallen = length;
	if (options.precision > length)
		totallen = options.precision;

	pad_before(options, totallen, prefix, prefixlen);
	/* print digits */
	outcr('0', totallen - length);
	for (i = length - 1; i >= 0; i--)
		outc(digits[i] + '0');

	pad_after(options, totallen + prefixlen);
}
