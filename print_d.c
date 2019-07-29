#include "holberton.h"
/**
 * print_d - Print digit.
 * @args: Incoming number.
 */
void print_d(va_list args, Options options)
{
	int y, n = va_arg(args, int);

	(void)options;
	if (n > 0)
	{
		n *= -1;
		for (y = 1000000000; y > 0; y /= 10)
		{
			if (n / y != 0)
			{
				outc(((-n / y) % 10) + '0');
			}
		}
	}
	else if (n == 0)
	{
		outc('0');
	}
	else if (n < 0)
	{
		outc('-');
		for (y = 1000000000; y > 0; y /= 10)
		{
			if (n / y != 0)
			{
				if (n < -2147483647)
					outc((((-n / y) % 10) * -1) + '0');
				else
					outc(((-n / y) % 10) + '0');
			}
		}
	}
}
