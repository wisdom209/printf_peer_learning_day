#include "main.h"

/**
 * print_ptr - print_ptr
 * @i: i
 * @ptr: ptr
 * @format: format
 * @count: count
 * Return: int
 */
int print_ptr(int *i, va_list ptr, const char *format, int *count)
{
	if (format[*i + 1] == 'p')
	{
		uintptr_t num = (uintptr_t)va_arg(ptr, void *);

		if (num == 0)
		{
			(write(1, "(nil)", 6));
			*count = *count + 5;
		}
		else
			convert_decimal(num, 16, 0, count, 1);

		*i = *i + 1;
	}
	return (0);
}
