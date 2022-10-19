#include "main.h"

/**
 * _putchar - putchar
 * @c: c
 *
 * Return: int
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_unsigned_digits - print_unsigned_digits
 * @i: i
 * @ptr: ptr
 * @format: format
 * @count: count
 * Return: int
 */
int print_unsigned_digits(int *i, va_list ptr, const char *format, int *count)
{
	if (format[*i + 1] == 'u')
	{
		int num = va_arg(ptr, int);

		if (num < 0)
			return (-1);

		if (num <= INT_MAX && num >= INT_MIN)
			print_num(num, count);

		*i = *i + 1;
	}
	return (0);
}
/**
 * print_binary - print_binary
 * @i: i
 * @ptr: ptr
 * @format: format
 * @count: count
 * Return: int
 */
int print_binary(int *i, va_list ptr, const char *format, int *count)
{
	if (format[*i + 1] == 'b')
	{
		unsigned int num = va_arg(ptr, unsigned int);

		convert_decimal(num, 2, 0, count, 0);

		*i = *i + 1;
	}
	return (0);
}
/**
 * print_hex_upper - print_hex_upper
 * @i: i
 * @ptr: ptr
 * @format: format
 * @count: count
 * Return: int
 */
int print_hex_upper(int *i, va_list ptr, const char *format, int *count)
{
	if (format[*i + 1] == 'X')
	{
		int num = va_arg(ptr, int);

		convert_decimal(num, 16, 1, count, 0);

		*i = *i + 1;
	}
	return (0);
}
/**
 * print_hex_lower - print_hex_lower
 * @i: i
 * @ptr: ptr
 * @format: format
 * @count: count
 * Return: int
 */
int print_hex_lower(int *i, va_list ptr, const char *format, int *count)
{
	if (format[*i + 1] == 'x')
	{
		int num = va_arg(ptr, int);

		convert_decimal(num, 16, 0, count, 0);

		*i = *i + 1;
	}
	return (0);
}


