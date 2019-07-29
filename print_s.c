#include "holberton.h"
/**
 * print_s - Print string.
 * @args: Incoming string.
 * Return: Number of bytes
 */
void print_s(va_list args)
{
	char *s = va_arg(args, char *);
	int i;

	for (i = 0; s[i] != '\0'; i++)
		outc(s[i]);
}
