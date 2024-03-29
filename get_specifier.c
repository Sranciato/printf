#include "holberton.h"
#include "functions.h"
/**
 * get_spec - get specifer.
 * @s: specifier character.
 * Return: function pointer.
 */
Printer get_spec(char s)
{
	Spec array[] = {
		{'c', print_c},
		{'s', print_s},
		{'%', print_percent},
		{'d', print_d},
		{'i', print_d},
		{'b', print_b},
		{'u', print_u},
		{'o', print_o},
		{'x', print_x},
		{'X', print_X},
		{'S', print_S},
		{'p', print_p},
		{'R', print_R},
		{'r', print_r},
		{'\0', NULL}
	};

	int i = 0;

	while (array[i].name != '\0')
	{
		if (s == array[i].name)
			return (array[i].f);
		i++;
	}
	return (NULL);
}
