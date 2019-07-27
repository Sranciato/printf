#include "holberton.h"
/**
 * print_percent - Print '%'.
 * @args: unused
 * Return: Number of bytes
 */
int print_percent(va_list args)
{
	char c = '%';
	write(1, &c, 1);
	return (1);
}
