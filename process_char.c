#include "holberton.h"

/**
 * process_item - process one character or specifier in the format string
 *
 * @format: pointer to  pointer to current char
 * @args: varargs
 * Return: number of characters printed
 */
int process_item(char **format, va_list args)
{
	Printer f;
	char c;

	/* eat 1 char */
	c = **format;
	*format += 1;

	/* Normal character */
	if (c != '%')
	{
		write(1, c, 1);
		return 1;
	}
	/* % */

	/* eat format specifier */
	c = **format;
	*format += 1;

	/* call print function */
	f = get_spec(c);
	if (f)
		return f(args);

	/* invalid */
	return 0;
}
