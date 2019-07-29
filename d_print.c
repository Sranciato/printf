#include "holberton.h"
/**
 * print_d - Print digit.
 * @args: arg list
 * @options: format options
 */
void print_d(va_list args, Options options)
{
	long int y, n;

	GET_SIZED(n, options, args, int);

	if (n > 0)
	{
		n *= -1;
		for (y = MAX_DIGIT; y > 0; y /= 10)
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
		for (y = MAX_DIGIT; y > 0; y /= 10)
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
