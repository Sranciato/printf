#include "../holberton.h"

int main(int argc, char **argv)
{
	if (argc == 4)
	{
	int a=atoi(argv[1]);
	int b=atoi(argv[2]);
	int c=atoi(argv[3]);

	_printf("test: [%*.*d]\n", a,b,c);
	_printf("test: [%*.*d]\n", a,b,c);
}
	_printf("d: [%.70d] [%+5.9hd] [%+ld]\n", -3, 123, -3141592653589793238L);
	 printf("d: [%.70d] [%+5.9hd] [%+ld]\n", -3, 123, -3141592653589793238L);

	_printf("u: [%-10.3u] [%05hu] [%lu]\n", 3, 123, 3141592653589793238L);
	printf("u: [%-10.3u] [%05hu] [%lu]\n", 3, 123, 3141592653589793238L);

	_printf("o: [%-10.3o] [%#05ho] [%lo]\n", 3, 123, 3141592653589793238L);
	printf("o: [%-10.3o] [%#05ho] [%lo]\n", 3, 123, 3141592653589793238L);

	_printf("x: [%.9x] [%#5hX] [%lX]\n", 0, 123, 3141592653589793238L);
	printf("x: [%.9x] [%#5hX] [%lX]\n", 0, 123, 3141592653589793238L);

	_printf("s: [%-9.4s]\n", "test123");
	printf("s: [%-9.4s]\n", "test123");

	_printf("S: [%S]\n", "hello\x12\naaa\xFF");

	return (0);
}
