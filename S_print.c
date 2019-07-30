#include "holberton.h"
/**
 * print_S - Print string.
 * @args: Incoming string.
 * @options: Options.
 * Return: Number of bytes
 */
void print_S(va_list args, Options options)
{
	int a[32];
	char *s = va_arg(args, char *);
	int i, n, j, length = 0;

	/* get length */
	if (s)
		for (i = 0; s[i]; i++)
			if (s[length] < 32 || s[length] >= 127) /* "\xNN" - 4 chars */
				length += 4;
			else
				length += 1;
	else
		length = 6; /* "(null)" */
	/* note: precision flag doesn't really work... but it's not required */
	if (options.precision >= 0 && length > options.precision)
		length = options.precision;
	pad_before(options, length, NULL, 0);
	/* print string */
	if (s)
		for (i = 0; s[i]; i++)
			if (s[i] < 32 || s[i] >= 127)
			{
				out("\\x", 2);
				n = s[i];
				for (j = 0; j < 2; j++)
				{
					a[j] = n & 15;
					n >>= 4;
				}
				for (j = (j - 1); j >= 0; j--)
					if (a[j] <= 9)
						outc(a[j] + '0');
					else
						outc((a[j] - 10) + 'A');
			}
			else
				outc(s[i]);
	else
		out("(null)", 6);
	pad_after(options, length);
}
