#include "holberton.h"
/**
 * print_b - Print character.
 * @args: Incoming character.
 * Return: Number of bytes
 */
int print_b(va_list args)
{
	int a[10], i, n = va_arg(args, int);

	for (i = 0; n > 0; i++)
	{
		a[i] = n % 2;
		n /= 2;
	}
	for (i = (i - 1); i >= 0; i--)
	{
		_putchar(a[i] + '0');
	}
	return (sizeof(int));
}