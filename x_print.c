#include "holberton.h"
/**
 * print_x - Print character.
 * @args: arg list
 * @options: format options
 */
void print_x(va_list args, Options options)
{
	int a[64], i;
	long unsigned int n;

	GET_SIZED(n, options, args, unsigned int);

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
			outc(a[i] + 'W');
	}
}
/**
 * print_X - print uppercase hex.
 * @args: arg list
 * @options: format options
 */
void print_X(va_list args, Options options)
{
	int a[64], i;
	long unsigned int n;

	GET_SIZED(n, options, args, unsigned int);

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
			outc((a[i] - 10) + 'A');
	}
}
