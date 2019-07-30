#include "holberton.h"
/**
 * print_R - rot 13.
 * @args: incoming strings.
 * @ops: incoming options.
 * Return: rot 13 string.
 */
void print_R(va_list args, Options ops)
{
	int i, x;
	char s[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char s2[] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWQYZABCDEFGHIJKLM";
	char *p = va_arg(args, char *);

	(void)ops;
	if (p)
	{
		for (i = 0; p[i] != '\0'; i++)
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
	}
}
