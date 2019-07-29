#include "holberton.h"
/**
 * print_u - Print unsigned integer.
 * @args: arg list
 * @options: format options
 */
void print_u(va_list args, Options options)
{
	unsigned long int y, n;

	GET_SIZED(n, options, args, unsigned int);

	if (n > 0)
	{
		for (y = MAX_DIGIT * 10UL; y > 0; y /= 10)
		{
			if (n / y != 0)
			{
				outc(((n / y) % 10) + '0');
			}
		}
	}
	else if (n == 0)
	{
		outc('0');
	}
}
