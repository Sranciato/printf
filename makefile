CC=gcc

test1: printf.o process_item.o get_specifier.o tests/test1.o print_c.o print_s.o print_percent.o print_d.o _putchar.o print_b.o
	$(CC) printf.o process_item.o get_specifier.o tests/test1.o print_c.o print_s.o print_percent.o print_d.o _putchar.o print_b.o
