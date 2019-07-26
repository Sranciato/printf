CC=gcc

test1: printf.o process_item.o get_specifier.o tests/test1.o
	$(CC) printf.o process_item.o get_specifier.o tests/test1.o
