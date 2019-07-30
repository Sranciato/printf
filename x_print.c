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
	int digits[64], i, length, prefixlen = 0;
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
	for (length = 0; n != 0; length++)
	{
		digits[length] = n & 15;
		n >>= 4;
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
	{
		if (digits[i] <= 9)
			outc(digits[i] + '0');
		else
			outc(digits[i] - 10 + a);
	}
	pad_after(options, length + prefixlen);
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
