#include "holberton.h"
/**
 * print_c - Print character.
 * @args: Incoming character.
 * Return: Number of bytes
 */
void print_c(va_list args, Options options)
{
	(void)options;
	outc(va_arg(args, int));
}
