#include "holberton.h"
/**
 * print_c - Print character.
 * @args: Incoming character.
 * Return: Number of bytes
 */
int print_c(va_list args)
{
	return outc(va_arg(args, int));
}
