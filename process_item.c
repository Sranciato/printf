#include "holberton.h"

/**
 * scan - read 1 char from format string, a-and move the pointer
 *
 * @format: format
 * Return: read char
 */
char scan(const char **format)
{
	char c = **format;

	*format += 1;
	return (c);
}

/**
 * scan_size - read length specifier
 * @format: format string
 * @cc: c
 * Return: 0-9, (none, hh, h, l, ll, j, z, t, L)
 */
int scan_size(const char **format, char *cc)
{
	if (*cc == 'h')
	{
		*cc = scan(format);
		return (2);
	}
	else if (*cc == 'l')
	{
		*cc = scan(format);
		return (3);
	}
	return (0);
}

/**
 * scan_int - read an integer from format, or * (read from args)
 *
 * @format: format
 * @cc: char in main parser
 * @args: args
 * Return: read integer or -1
 */
int scan_int(const char **format, char *cc, va_list args)
{
	int ret = 0;
	char c = *cc;

	if (c == '*')
	{
		*cc = scan(format);
		return (va_arg(args, int));
	}
	if (c < '0' || c > '9')
		return (-1);

	while (c >= '0' && c <= '9')
	{
		ret = ret * 10 + (c - '0');
		*cc = c = scan(format);
	}
	return (ret);
}

/**
 * process_item - process one character or specifier in the format string
 *
 * @format: pointer to  pointer to current char
 * @args: varargs
 * Return: number of characters printed
 */
void process_item(const char **format, va_list args)
{
	Printer f;
	char c;
	Options options = {0, 0, 0, 0, ' ', -1, -1, 0};
	const char *start = *format;

	c = scan(format); /* eat 1 char */
	if (c != '%') /* char is not %: print it and return */
	{
		outc(c);
		return;
	}
	while (1) /* read options */
	{
		c = scan(format);
		if (c == '-')
			options.minus = 1;
		else if (c == '+')
			options.plus = 1;
		else if (c == ' ')
			options.space = 1;
		else if (c == '#')
			options.hash = 1;
		else if (c == '0')
			options.pad = '0';
		else
			break;
	}
	options.length = scan_int(format, &c, args);
	if (c == '.')
		options.precision = scan_int(format, &c, args);
	options.size = scan_size(format, &c);
	if (c == '\0')
		(*format)--;
	f = get_spec(c);
	if (f) /* call print function */
		f(args, options);
	else
		out(start, *format - start);
}

/*
 * printf("\nflags: +:%d _:%d #:%d -:%d\n", o_plus, o_space, o_hash, o_minus);
 * printf("\npadding: '%c'\n", o_pad);
 * printf("length: %d\n", o_length);
 * printf("precision: %d\n", o_precision);
 * printf("char: %c\n", c);
 */
