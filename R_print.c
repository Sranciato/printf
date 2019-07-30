#include "holberton.h"
/**
 * print_R - rot 13.
 * @args: incoming strings.
 * @ops: incoming options.
 * Return: rot 13 string.
 */
void print_R(va_list args, Options options)
{
	int i, x, length = 0;
	char s[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char s2[] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWQYZABCDEFGHIJKLM";
	char *p = va_arg(args, char *);

	if (p)
		while (p[length] != '\0')
			length ++;

	if (options.precision >= 0 && length > options.precision)
		length = options.precision;

	pad_before(options, length, NULL, 0);
	for (i = 0; i < length; i++)
	{
		for (x = 0; s[x] != '\0'; x++)
		{
			if (p[i] == s[x])
			{
				outc(s2[x]);
				break;
			}
		}
		if (!(p[i] >= 'a' && p[i] <= 'z') && !(p[i] >= 'A' && p[i] <= 'Z'))
		{
			outc(p[i]);
		}
	}
	pad_after(options, length);
}
