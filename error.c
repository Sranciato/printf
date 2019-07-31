#include "holberton.h"

/**
 * print_number_sub - magic recursive printer
 *
 * @n: number
 */
void print_number_sub(int n)
{
	if (!n)
		return;
	print_number_sub(n / 10);
	outc('0' + n % 10);
}

/**
 * print_number - print number
 *
 * @n: number to print
 */
void print_number(int n)
{
	if (n)
		print_number_sub(n);
	else
		outc('0');
}

/**
 * output_invalid - matching behavior of gcc printf
 *
 * @options: options
 * @spec: specifier char
 */
void output_invalid(Options options, char spec)
{
	outc('%');
	if (options.hash)
		outc('#');
	if (options.plus)
		outc('+');
	if (options.space)
		outc(' ');
	if (options.minus)
		outc('-');
	if (options.length != -1)
		print_number(options.length);
	if (options.precision != -1)
	{
		outc('.');
		print_number(options.precision);
	}
	outc(spec);
}
