#include "holberton.h"
/**
 * print_u - Print unsigned integer.
 * @args: Incoming integer.
 */
void print_u(va_list args, Options options)
{
	unsigned int y;
	unsigned int n = va_arg(args, unsigned int);

	(void)options;
	if (n > 0)
	{
		for (y = 1000000000; y > 0; y /= 10)
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
