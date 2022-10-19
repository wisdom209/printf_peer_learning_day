#include "main.h"
/**
 * print_percent - print percent
 * @i: i
 * @format: format
 * @count: count
 *
 * Return: int
 */
int print_percent(int *i, const char *format, int *count)
{
	if (format[*i + 1] == '%')
	{
		_putchar('%');

		*count = *count + 1;

		*i = *i + 1;
	}
	return (0);
}
