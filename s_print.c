#include "holberton.h"
/**
 * print_s - Print string.
 * @args: arg list
 * @options: format options
 */
void print_s(va_list args, Options options)
{
	char *s = va_arg(args, char *);
	int length;
	char *null = "(null)";

	if (!s)
		s = null;
	/* get length */
	for (length = 0; s[length]; length++)
		;
	if (options.precision != -1 && length > options.precision)
	{
		length = options.precision;
		if (s == null)
			length = 0;
	}
	/* print */
	pad_before(options, length, NULL, 0);
	out(s, length);
	pad_after(options, length);
}
