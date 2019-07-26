#ifndef PRINT_F
#define PRINT_F

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

typedef int (*Printer)(va_list);

typedef struct {
	char name;
	Printer f;
} Spec;

int _printf(const char *format, ...);

int process_item(const char **format, va_list args);

Printer get_spec(char c);

#endif
