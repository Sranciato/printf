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
	char c, o_pad = ' ';
	int o_plus = 0, o_space = 0, o_hash = 0, o_minus = 0;
	int o_length = -1, o_precision = -1;
	const char *start = *format;

	/* eat 1 char */
	c = scan(format);
	/* char is not %: print it and return */
	if (c != '%')
	{
		outc(c);
		return;
	}
	/* read options */
	while (1)
	{
		c = scan(format);
		if (c == '+')
			o_plus = 1;
		else if (c == ' ')
			o_space = 1;
		else if (c == '#')
			o_hash = 1;
		else if (c == '0')
			o_pad = '0';
		else if (c == '-')
			o_minus = 1;
		else
			break;
	}
	o_length = scan_int(format, &c, args);
	if (c == '.')
		o_precision = scan_int(format, &c, args);
	(void)o_plus, (void)o_space, (void)o_hash, (void)o_minus, (void)o_pad;
	(void)o_length, (void)o_precision;
	/* call print function */
	f = get_spec(c);
	if (f)
		f(args/*, o_plus, o_space, o_hash, o_minus, o_pad, o_length, o_precision*/);
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
