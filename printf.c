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
	char *ptr;
	int totalprinted = 0;
	va_list args;

	va_start(args, format);

	ptr = format;
	while(ptr && *ptr)
		totalprinted += process_item(&ptr, args);

	va_end(args);

	return totalprinted;
}
