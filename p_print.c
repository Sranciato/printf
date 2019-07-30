#include "holberton.h"

/**
 * print_p - print pointer
 *
 * @args: args
 * @options: options
 */
void print_p(va_list args, Options options)
{
	int digits[64], i, length;
	size_t n = (size_t)va_arg(args, void *);

	if (n == 0)
	{
		pad_before(options, 5, NULL, 0);
		out("(nil)", 5);
		pad_after(options, 5);
		return;
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

	pad_before(options, 2 + length, NULL, 0);
	out("0x", 2);
	/* print digits */
	for (i = length - 1; i >= 0; i--)
	{
		if (digits[i] <= 9)
			outc(digits[i] + '0');
		else
			outc(digits[i] - 10 + 'a');
	}
	pad_after(options, 2 + length);
}
