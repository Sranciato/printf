#include "../holberton.h"

int main(int argc, char **argv)
{
	if (argc == 4)
	{
	int a=atoi(argv[1]);
	int b=atoi(argv[2]);
	int c=atoi(argv[3]);

	_printf("test: [%+*.*d]\n", a,b,c);
	_printf("test: [%+*.*d]\n", a,b,c);
}

	int x = 0;
	

  //_printf("%-99lu %hd %d", ~0L, 1<<15, 1<<31);
	//printf("%-99lu %hd %d", ~0L, 1<<15, 1<<31);

	_printf("d: [%10.*u]\n",6,8);
	printf("d: [%10.*u]\n",6,8);
	//printf("d: [%.");

	_printf("u: [%-10.3u] [%05hu] [%lu]\n", 3, 123, 1L<<63);
	printf("u: [%-10.3u] [%05hu] [%lu]\n", 3, 123, 1L<<63);

	_printf("o: [%-10.3b] [%#05ho] [%lo]\n", 3, 123, 3141592653589793238L);
	//printf("o: [%-10.3b] [%#05ho] [%lo]\n", 3, 123, 3141592653589793238L);

	_printf("x: [%.9x] [%#5hX] [%lX]\n", 0, 123, 3141592653589793238L);
	printf("x: [%.9x] [%#5hX] [%lX]\n", 0, 123, 3141592653589793238L);

	x = _printf(argv[1], -5);
	printf("%d\n",x);
	x = printf(argv[1], -5);
	printf("%d\n",x);

	_printf("S: [%S]\n", "hello\x12\naaa\xFF");

	return (0);
}
