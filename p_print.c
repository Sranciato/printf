#include "holberton.h"
/**
 * print_p - Print pointer
 * @args: arg list
 * @options: format options
 */
void print_p(va_list args, Options options)
{
	int a[sizeof(size_t) * 8], i;
	size_t n = (size_t)va_arg(args, void *);

	(void)options;
	if (!n)
	{
		out("(nil)", 5);
		return;
	}

	out("0x", 2);

	if (n == 0)
	{
		outc('0');
		return;
	}
	for (i = 0; n != 0; i++)
	{
		a[i] = n & 15;
		n >>= 4;
	}
	for (i = (i - 1); i >= 0; i--)
	{
		if (a[i] <= 9)
			outc(a[i] + '0');
		else
			outc(a[i] - 10 + 'a');
	}
}
