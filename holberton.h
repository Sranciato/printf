#ifndef PRINT_F
#define PRINT_F

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

typedef int (*Printer)(void *);

typedef struct {
	char name;
	Printer f;
} Spec;

int _printf(const char *format, ...);

#endif
