#include "holberton.h"

/**
 * _printf - printf
 *
 * @format: format string
 * ...: args
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	const char *ptr;
	va_list args;

	va_start(args, format);

	/* reset the printed char counter */
	out(NULL, -1);

	ptr = format;
	while (ptr && *ptr)
		process_item(&ptr, args);

	va_end(args);

	/* get the number of chars printed */
	return (out(NULL, -2));
}
