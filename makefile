CC=gcc
CFLAGS=-Werror -Wextra -Wall -pedantic


test1: printf.o process_item.o get_specifier.o output.o tests/test1.o print_c.o print_s.o print_percent.o print_d.o _putchar.o print_b.o print_u.o print_o.o print_x.o print_p.o
	$(CC) $(CFLAG) printf.o process_item.o get_specifier.o output.o tests/test1.o print_c.o print_s.o print_percent.o print_d.o _putchar.o print_b.o print_u.o print_o.o print_x.o print_p.o
