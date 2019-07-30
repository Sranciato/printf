#include "../holberton.h"

int main(void)
{
	int x;

	x=_printf("test%c\n",'!');
	_printf("%d\n", x);
	x=_printf("test%%hi\n");
	_printf("%d\n", x);
	x=_printf("string: %s\n", "word");
	_printf("%d\n", x);
	x=_printf("numbers: %d %u\n", 398, 1<<31);
	_printf("%d\n", x);
	x=_printf("binary: %b, %b, %b, %b,\n", 46, 1<<31, -1, 0);
	_printf("%d\n", x);
	x=_printf("unsigned: %u\n", -1);
	_printf("%u\n", x);

	x=_printf("invalid: %-11Z\n");
	_printf("%d\n", x);

	x=_printf("null string: %s\n", NULL);
	_printf("%d\n", x);

	x=_printf("unclosed specifier: %+10", 1);
	_printf("%d\n", x);

	x=_printf(NULL);

	_printf("%d\n", x);

	_printf("Unsigned octal:[%o], %o, %o, %o\n", 1<<31, -1, 0, 45);

	_printf("Unsigned hexadecimal:[%x, %x, %x, %x]\n", 1<<31, -1, 0, 45);
	printf("Unsigned hexadecimal:[%x, %x, %x, %x]\n", 1<<31, -1, 0, 45);

	_printf("Unsigned hexadecimal:[%X, %X, %X, %X]\n", 1<<31, -1, 0, 45);

	_printf("%S\n", "Holberton\nSchool");

	_printf("%R\n", "hello holberton");

	x = _printf("%r\n", "hello holberton");
	_printf("length: %+d length: %#d\n", x);

	return (0);
}
