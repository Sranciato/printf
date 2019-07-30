#include "holberton.h"

/**
 * out - print multiple chars
 *  ex: out("hello", 5);
 *
 * This function keeps track of the total number of printed chars
 *  to reset the count, call: out(NULL, -1)
 *  to get the count, call: out(NULL, -2)
 * (This is a sort of hack because global variables aren't allowed)
 *
 * @data: pointer to data to print
 * @length: number of bytes
 * Return: number of chars printed
 */
int out(const char *data, int length)
{
	static int totalprinted;
	static char buffer[1024];
	static unsigned int bufpos;
	int i;

	if (data == NULL)
	{
		if (length == -1)
		{
			totalprinted = 0;
			bufpos = 0;
		}
		else if (length == -2)
		{
			write(1, buffer, bufpos);
			return (totalprinted);
		}
		return (0);
	}

	for (i = 0; i < length; i++)
	{
		if (bufpos >= LENGTH(buffer))
		{
			write(1, buffer, LENGTH(buffer));
			bufpos = 0;
		}
		buffer[bufpos++] = data[i];
	}
	totalprinted += length;

	return (length);
}

/**
 * outc - print 1 char
 *  ex: outc('x');
 *
 * @c: char
 */
void outc(char c)
{
	out(&c, 1);
}

/**
 * outcr - output a character, repeated multiple times
 *  ex: outcr('z', 5) -> zzzzz
 * @c: char
 * @count: number of times. if less than 1, nothing happens
 */
void outcr(char c, int count)
{
	int i;

	for (i = 0; i < count; i++)
		outc(c);
}

/*
 * Pad functions
 *
 * All format specifiers allow specifying a MINIMUM length.
 * If the text to be printed is shorter than this,
 * printf outputs spaces (or 0s) before (or after) the text
 * so it is the correct length (depending on the 0 and - flags)
 *
 * When printing text:
 * 1: calculate the number of characters that will be printed.
 * 2: call pad_before(options, number, prefix, prefixlen)
 * 3: print your text
 * 4: call pad_after(options, number)
 */

/**
 * pad_before - print padding before text, depending on options
 * @options: options
 * @length: length of string to be printed
 * @prefix: prefix to print (sign, 0x, etc.) or NULL if none
 * @prefixlen: length of prefix
 */
void pad_before(Options options, int length, char *prefix, int prefixlen)
{
	if (!options.minus)
	{
		/* if padding with 0s, print prefix before padding */
		if (prefix && options.pad == '0')
			out(prefix, prefixlen);
		/* print padding */
		outcr(options.pad, options.length - length - prefixlen);
		/* if padding with spaces, print prefix after padding */
		if (prefix && options.pad == ' ')
			out(prefix, prefixlen);
	}
	else if (prefix)
	{
		out(prefix, prefixlen);
	}
}

/**
 * pad_after - print padding after text, depending on options
 * @options: options
 * @length: length of string that was printed
 */
void pad_after(Options options, int length)
{
	if (options.minus)
		outcr(options.pad, options.length - length);
}
