#include "holberton.h"
/**
 * print_c - Print character.
 * @args: Incoming character.
 * Return: Number of bytes
 */
int print_c(va_list args)
{
	char c = va_arg(args, int);

	write(1, &c, 1);
	return (1);
}
