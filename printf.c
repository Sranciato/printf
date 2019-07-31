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
	int totalprinted;

	if (!format)
		return (-1);

	va_start(args, format);

	/* reset the printed char counter */
	out(NULL, -1);

	ptr = format;
	while (ptr && *ptr)
		process_item(&ptr, args);

	va_end(args);

	/* calling out() this way will finish outputting everything in the buffer */
	/* and return the total number of characters printed */
	totalprinted = out(NULL, -2);

	/* if an error occurred, return -1 */
	if (ptr == NULL)
		return (-1);

	return (totalprinted);
}
