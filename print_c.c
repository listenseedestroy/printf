#include "main.h"
#include <stdarg.h>
/**
 * print_c - prints a character.
 * @val: arguments.
 * Return: integer.
 */
int printf_c(va_list val)
{
	char s;

	s = va_arg(val, int);
	_putchar(s);
	return (1);
}
