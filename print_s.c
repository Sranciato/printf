#include "holberton.h"
/**
 * print_s - Print string.
 * @args: Incoming string.
 * Return: Number of bytes
 */
void print_s(va_list args, Options options)
{
	char *s = va_arg(args, char *);
	int i;

	(void)options;
	if (s)
	{
	for (i = 0; s[i] != '\0'; i++)
		outc(s[i]);
	}
	else
		out("(null)", 6);
}
