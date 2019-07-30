#include "holberton.h"

/**
 * print_o - print octal
 *
 * @args: args
 * @options: options
 */
void print_o(va_list args, Options options)
{
	int digits[64], i, length, prefixlen = 0;
	char *prefix = NULL;
	unsigned long int n;

	GET_SIZED(n, options, args, unsigned int);

	if (options.hash && n != 0)
	{
		prefix = "0";
		prefixlen = 1;
	}

	/* read digits */
	for (length = 0; n != 0; length++)
	{
		digits[length] = n & 7;
		n >>= 3;
	}
	for (; length < options.precision; length++)
		digits[length] = 0;
	/* special case if n was 0 */
	if (length == 0)
	{
		digits[0] = 0;
		length = 1;
	}

	pad_before(options, length, prefix, prefixlen);
	/* print digits */
	for (i = length - 1; i >= 0; i--)
		outc(digits[i] + '0');

	pad_after(options, length + prefixlen);
}
