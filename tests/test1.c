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
	_printf("d: [%.0u]\n",0);
	printf("d: [%.0u]\n",0);
	//printf("d: [%.");

	_printf("u: [%-10.3u] [%05hu] [%lu]\n", 3, 123, 1L<<63);
	printf("u: [%-10.3u] [%05hu] [%lu]\n", 3, 123, 1L<<63);

	_printf("o: [%-10.3b] [%#05ho] [%lo]\n", 3, 123, 3141592653589793238L);
	//printf("o: [%-10.3b] [%#05ho] [%lo]\n", 3, 123, 3141592653589793238L);

	_printf("x: [%.9x] [%#5hX] [%lX]\n", 0, 123, 3141592653589793238L);
	printf("x: [%.9x] [%#5hX] [%lX]\n", 0, 123, 3141592653589793238L);

	_printf("s: [%-.3s]\n", argv[1]);
	printf("s: [%-.3s]\n", argv[1]);

	_printf("S: [%S]\n", "hello\x12\naaa\xFF");

	return (0);
}
