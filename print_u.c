#include "holberton.h"
/**
 * print_u - Print unsigned integer.
 * @args: Incoming integer.
 * Return: Number of bytes.
 */
void print_u(va_list args)
{
	unsigned int y;
	unsigned int n = va_arg(args, unsigned int);
	unsigned int printed = 0;

	if (n > 0)
	{
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
}
