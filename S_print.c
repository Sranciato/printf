#include "holberton.h"
/**
 * print_S - Print string.
 * @args: Incoming string.
 * @ops: Options.
 * Return: Number of bytes
 */
void print_S(va_list args, Options ops)
{
	int a[32];
	char *s = va_arg(args, char *);
	int i, n, j;

	(void)ops;
	if (s)
	{
		for (i = 0; s[i] != '\0'; i++)
			if (s[i] < 32 || s[i] >= 127)
			{
				out("\\x", 2);
				n = s[i];
				if (n == 0)
				{
					outc('0');
					continue;
				}
				for (j = 0; j < 2; j++)
				{
					a[j] = n & 15;
					n >>= 4;
				}
				for (j = (j - 1); j >= 0; j--)
				{
					if (a[j] <= 9)
						outc(a[j] + '0');
					else
						outc((a[j] - 10) + 'A');
				}
			}
			else
				outc(s[i]);
	}
	else
		out("(null)", 6);
}
