#include "holberton.h"
/**
 * print_percent - Print string.
 * @args: Incoming string.
 * Return: Number of bytes
 */
int print_percent(va_list args)
{
	char c = va_arg(args, int);

	c = '%';
	write(1, &c, 1);
	return (1);
}
