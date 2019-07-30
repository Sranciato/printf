#include "holberton.h"

/**
 * print_hex - print hexadecimal number
 *
 * @args: args
 * @options: options
 * @a: first letter ('A' or 'a')
 */
void print_hex(va_list args, Options options, char a)
{
	int digits[64], i, length, prefixlen = 0, totallen;
	char *prefix = NULL;
	unsigned long int n;

	GET_SIZED(n, options, args, unsigned int);

	if (options.hash && n != 0)
	{
		if (a == 'A')
			prefix = "0X";
		else
			prefix = "0x";
		prefixlen = 2;
	}

	/* read digits */
	for (length = 0; n != 0 || (length == 0 && options.precision != 0); length++)
	{
		digits[length] = n & 15;
		n >>= 4;
	}

	totallen = length;
	if (options.precision > length)
		totallen = options.precision;

	pad_before(options, totallen, prefix, prefixlen);
	/* print digits */
	outcr('0', totallen - length);
	for (i = length - 1; i >= 0; i--)
	{
		if (digits[i] <= 9)
			outc(digits[i] + '0');
		else
			outc(digits[i] - 10 + a);
	}
	pad_after(options, totallen + prefixlen);
}

/**
 * print_x - print lowercase hex
 * @args: arg list
 * @options: format options
 */
void print_x(va_list args, Options options)
{
	print_hex(args, options, 'a');
}

/**
 * print_X - print uppercase hex.
 * @args: arg list
 * @options: format options
 */
void print_X(va_list args, Options options)
{
	print_hex(args, options, 'A');
}
