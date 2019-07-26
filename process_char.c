#include "holberton.h"

/**
 * process_item - process one character or specifier in the format string
 *
 * @format: pointer to current position in format string
 * @args: varargs
 * Return: number of characters processed
 */
int process_item(char *format, va_list args)
{
	Printer f;

	/* Normal character */
	if (*format != '%')
	{
		write(1, *format, 1);
		return 1;
	}
	/* % */
	f = get_spec(*format);
	if (f)
		return f(args);
	
	return 0;
}
