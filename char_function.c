#include "main.h"

/**
 * print_char - print char
 * @i: i
 * @ptr: ptr
 * @format: format
 * @count: count
 *
 * Return: int
 */
int print_char(int *i, va_list ptr, const char *format, int *count)
{
	if (format[*i + 1] == 'c')
	{
		char c = va_arg(ptr, int);

		if (c == 0)
			return (-1);

		_putchar(c);
		*count = *count + 1;
		*i = *i + 1;
	}
	return (0);
}
