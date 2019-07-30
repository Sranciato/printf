#include "holberton.h"
/**
 * print_c - Print character.
 * @args: arg list
 * @options: format options
 */
void print_c(va_list args, Options options)
{
	(void)options;
	pad_before(options, 1, NULL, 0);
	outc(va_arg(args, int));
	pad_after(options, 1);
}
