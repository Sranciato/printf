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
 * Return: number of bytes printed
 */
int out(char *data, int length)
{
	static int totalprinted;
	int printed;

	if (data == NULL)
	{
		if (length == -1)
			totalprinted = 0;
		if (length == -2)
			return (totalprinted);
		return (0);
	}

	printed = write(1, data, length);
	totalprinted += printed;

	return (printed);

	/* eventually this will write to a buffer */
}

/**
 * outc - print 1 char
 *  ex: outc('x');
 *
 * @c: char
 * Return: number of chars printed (1)
 */
int outc(char c)
{
	return (out(&c, 1));
}
