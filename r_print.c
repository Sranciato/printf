#include "holberton.h"
/**
 * print_r - Print reverse string.
 * @args: Incoming argument.
 * @ops: options for specifiers.
 * Return: Number of bytes.
 */
void print_r(va_list args, Options options)
{
	int length;
	char *s = va_arg(args, char *);

	if (s)
		for (length = 0; s[length] != '\0'; length++)
		{
		}
	else
		length = 0;

	if (options.precision >= 0 && length > options.precision)
		length = options.precision;

	pad_before(options, length, NULL, 0);
	for (length = length - 1; length >= 0; length--)
	{
		outc(s[length]);
	}
	pad_after(options, length);
}
