#include "holberton.h"
/**
 * print_b - Print character.
 * @args: Incoming character.
 * Return: Number of bytes
 */
void print_b(va_list args, Options options)
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
		a[i] = n & 1;
		n >>= 1;
	}
	for (i = (i - 1); i >= 0; i--)
	{
		outc(a[i] + '0');
	}
}
