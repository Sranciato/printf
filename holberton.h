#ifndef PRINT_F
#define PRINT_F

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

typedef int (*Printer)(va_list);

typedef struct {
	char name;
	Printer f;
} Spec;

int _printf(const char *format, ...);

int process_char(char **format, va_list args);

#endif
