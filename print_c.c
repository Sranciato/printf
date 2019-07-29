#include "holberton.h"
/**
 * print_c - Print character.
 * @args: arg list
 * @options: format options
 */
void print_c(va_list args, Options options)
{
	(void)options;
	outc(va_arg(args, int));
}
