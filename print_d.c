#include "holberton.h"
/**
 * print_d - Print digit.
 * @args: Incoming number.
 * Return: Number of bytes
 */
int print_d(va_list args)
{
	int y, n = va_arg(args, int);

	if (n > 0)
	{
		n *= -1;
		for (y = 1000000000; y > 0; y /= 10)
		{
			if (n / y != 0)
			{
				_putchar(((-n / y) % 10) + '0');
			}
		}
	}
	else if (n == 0)
	{
		_putchar('0');
	}
	else if (n < 0)
	{
		_putchar('-');
		for (y = 1000000000; y > 0; y /= 10)
		{
			if (n / y != 0)
			{
				if (n < -2147483647)
					_putchar((((-n / y) % 10) * -1) + '0');
				else
					_putchar(((-n / y) % 10) + '0');
			}
		}
	}
	return (sizeof(int));
}
