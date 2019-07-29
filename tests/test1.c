#include "../holberton.h"

void main(void)
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
}
