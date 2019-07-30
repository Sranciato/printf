#include "holberton.h"
/**
 * print_r - Print reverse string.
 * @args: Incoming argument.
 * @ops: options for specifiers.
 * Return: Number of bytes.
 */
void print_r(va_list args, Options ops)
{
	int length;
	char *s = va_arg(args, char *);

	(void)ops;

	for (length = 0; s[length] != '\0'; length++)
	{
	}
	for (length = length - 1; length >= 0; length--)
	{
		outc(s[length]);
	}
}
