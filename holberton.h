#ifndef PRINT_F
#define PRINT_F

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

#define LENGTH(a) (sizeof(a) / sizeof((a)[0]))

typedef void (*Printer)(va_list);

typedef struct {
	char name;
	Printer f;
} Spec;

int out(char *data, int length);
int outc(char c);

int _printf(const char *format, ...);

void process_item(const char **format, va_list args);

Printer get_spec(char c);

#endif
