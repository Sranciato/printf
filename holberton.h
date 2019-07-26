#ifndef PRINT_F
#define PRINT_F

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

typedef struct {
	char name;
	int (*f)(void *);
} spec;

int _printf(const char *format, ...);

#endif
