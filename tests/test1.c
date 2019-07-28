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
	x=_printf("numbers: %d %d\n", 398, -24);
	_printf("%d\n", x);
	x=_printf("binary: %b\n", 46);
	_printf("%d\n", x);
}
