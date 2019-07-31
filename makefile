CC=gcc
CFLAGS=-Werror -Wextra -Wall -pedantic


test1: printf.o process_item.o get_specifier.o output.o tests/test1.o c_print.o s_print.o %_print.o d_print.o b_print.o u_print.o o_print.o x_print.o S_print.o p_print.o R_print.o r_print.o error.o
	$(CC) $(CFLAG) printf.o process_item.o get_specifier.o output.o tests/test1.o c_print.o s_print.o %_print.o d_print.o b_print.o u_print.o o_print.o x_print.o S_print.o p_print.o R_print.o r_print.o error.o
