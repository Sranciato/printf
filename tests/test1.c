#include "../holberton.h"

void main(void)
{
	_printf("test%c\n",'!');
	_printf("test%%hi\n");
	_printf("string: %s\n", "word");
	_printf("numbers: %d %d\n", 398, -24);
	_printf("binary: %b\n", 46);
}
