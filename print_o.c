#include "holberton.h"
/**
 * print_o - Print character.
 * @args: arg list
 * @options: format options
 */
void print_o(va_list args, Options options)
{
	int a[32], i;
	unsigned int n = va_arg(args, unsigned int);

	(void)options;
	if (n == 0)
	{
		outc('0');
		return;
	}
	for (i = 0; n != 0; i++)
	{
		a[i] = n & 7;
		n >>= 3;
	}
	for (i = (i - 1); i >= 0; i--)
	{
		outc(a[i] + '0');
	}
}
