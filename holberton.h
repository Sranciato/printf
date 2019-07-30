#ifndef PRINT_F
#define PRINT_F

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

#define LENGTH(a) (sizeof(a) / sizeof((a)[0]))

/**
 * struct Options - format specifier options
 * @minus: -, left align
 * @plus: +, display + before non-negative numbers
 * @space:  , display space before non-negatives
 * @hash: o: display 0/0x/0X before nonzero numbers or force decimal point
 * @pad: character to fill empty space with
 * @length: length
 * @precision: precision, or max string length
 * @size: size modifier
 */
typedef struct Options
{
	int minus;
	int plus;
	int space;
	int hash;
	char pad;
	int length;
	int precision;
	int size;
} Options;

typedef void (*Printer)(va_list, Options);

/**
 * struct Spec - function pointer and specifier.
 * @name: name of specifier.
 * @f: function pointer for get spec.
 *
 * Description: Specifier types.
 */
typedef struct Spec
{
	char name;
	Printer f;
} Spec;

int out(const char *data, int length);
void outc(char c);

int _printf(const char *format, ...);

void process_item(const char **format, va_list args);

Printer get_spec(char c);

#define GET_SIZED(n, options, args, type) do {			\
		if (options.size == 2)													\
			n = (short type) va_arg(args, type);					\
		else if (options.size == 3)											\
			n = va_arg(args, long type);									\
		else																						\
			n = va_arg(args, type);												\
	} while (0)

#define MAX_DIGIT 1000000000000000000

#endif
