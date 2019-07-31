#include "holberton.h"

/**
 * scan - read 1 char from format string, and m-move the pointer
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
 * scan_size - read length specifier (h or l)
 * @format: format string
 * @cc: c
 * Return: 0 (none), 2 (h), or 3 (l)
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

	/* if * instead of number, return value from arguments */
	if (c == '*')
	{
		*cc = scan(format);
		return (va_arg(args, int));
	}

	/* if there is no number return -1 */
	if (c < '0' || c > '9')
		return (-1);

	/* read all digits */
	while (c >= '0' && c <= '9')
	{
		ret = ret * 10 + (c - '0');
		*cc = c = scan(format);
	}

	return (ret);
}

/**
 * scan_options - read format specifier options
 * @format: pointer to the position pointer
 * @cc: pointer to current char
 * @args: printf's args
 * Return: options struct
 */
Options scan_options(const char **format, char *cc, va_list args)
{
	/* default options */
	Options options = {0, 0, 0, 0, ' ', -1, -1, 0};
	char c = *cc;

	/* read flags */
	while (1)
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
	/* read length */
	options.length = scan_int(format, &c, args);
	/* if . read precision */
	if (c == '.')
	{
		c = scan(format);
		options.precision = scan_int(format, &c, args);
		if (options.precision == -1) /* if there is no number */
			options.precision = 0; /* treat it like .0 */
	}
	/* read h or l flag */
	options.size = scan_size(format, &c);

	*cc = c;

	return (options);
}

/**
 * process_item - process one character or specifier in the format string
 *
 * @format: pointer to  pointer to current char
 * @args: varargs
 */
void process_item(const char **format, va_list args)
{
	Printer f;
	char c;
	Options options;
	const char *start = *format;

	/* eat 1 char */
	c = scan(format);
	/* char is not %: print it and exit */
	if (c != '%')
	{
		outc(c);
		return;
	}

	/* read options after % */
	options = scan_options(format, &c, args);
	/* if string ended, oops */
	if (c == '\0')
	{
		*format = NULL; /* signal error by setting pointer to NULL */
		return;
	}

	/* call print function if it exists */
	f = get_spec(c);
	if (f)
		f(args, options);
	else /* otherwise output the invalid specifier directly */
		out(start, *format - start);
}
