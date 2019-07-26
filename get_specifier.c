#include "holberton.h"
/**
 * get_spec - get specifer.
 * @s: specifier character.
 * Return: function pointer.
 */
int (*get_spec(char s))
{
	Spec array[] = {
		{'c', NULL}
		{'s', NULL}
		{'%', NULL}
		{NULL, NULL}
	};

	int i = 0;

	while (array[i].name != NULL)
	{
		if (s == array[i].name)
			return (Printer);
		i++;
	}
	return (NULL);
}
