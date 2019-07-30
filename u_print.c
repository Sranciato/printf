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
	int length, i;

	GET_SIZED(n, options, args, unsigned int);
	/* get length and digits */
	for (length = 0; n != 0; length++)
	{
		digits[length] = n % 10;
		n = n / 10;
	}
	/* if n was 0 */
	if (length == 0)
	{
		digits[0] = 0;
		length = 1;
	}
	/* increase length if less than precision */
	for (; length < options.precision; length++)
		digits[length] = 0;

	pad_before(options, length, NULL, 0);

	/* print digits */
	for (i = length - 1; i >= 0; i--)
		outc(digits[i] + '0');

	pad_after(options, length);
}
