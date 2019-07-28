#include "holberton.h"

/**
 * scan - read 1 char from format string and m-move the pointer
 *
 * @format: format string
 */
char scan(const char **format)
{
	char c = **format;

	*format += 1;
	return (c);
}

/**
 * process_item - process one character or specifier in the format string
 *
 * @format: pointer to  pointer to current char
 * @args: varargs
 * Return: number of characters printed
 */
int process_item(const char **format, va_list args)
{
	Printer f;
	char c;

	/* eat 1 char */
	c = scan(format);

	/* Normal character */
	if (c != '%')
	{
		write(1, &c, 1);
		return 1;
	}

	/* eat format specifier */
	c = scan(format);

	/* call print function */
	f = get_spec(c);
	if (f)
		return f(args);

	/* invalid */
	return 0;
}
