#include "holberton.h"
/**
 * print_d - Print digit.
 * @args: Incoming number.
 * Return: Number of bytes
 */
void print_d(va_list args)
{
	int y, n = va_arg(args, int);
	int printed = 0;

	if (n > 0)
	{
		n *= -1;
		for (y = 1000000000; y > 0; y /= 10)
		{
			if (n / y != 0)
			{
				printed += outc(((-n / y) % 10) + '0');
			}
		}
	}
	else if (n == 0)
	{
		printed += outc('0');
	}
	else if (n < 0)
	{
		printed += outc('-');
		for (y = 1000000000; y > 0; y /= 10)
		{
			if (n / y != 0)
			{
				if (n < -2147483647)
					printed += outc((((-n / y) % 10) * -1) + '0');
				else
					printed += outc(((-n / y) % 10) + '0');
			}
		}
	}
}
