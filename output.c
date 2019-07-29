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
