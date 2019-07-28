#include "holberton.h"

/**
 * out - print multiple chars
 *  ex: out("hello", 5);
 *
 * @buffer: pointer to data to print
 * @length: number of bytes
 * Return: number of bytes printed
 */
int out(char *data, int length)
{
	return write(1, data, length);
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
	return out(&c, 1);
}
