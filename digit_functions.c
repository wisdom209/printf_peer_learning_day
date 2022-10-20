#include "main.h"

/**
 * print_digits - print digits
 * @i: i
 * @ptr: ptr
 * @format: format
 * @count: count
 * Return: int
 */
int print_digits(int *i, va_list ptr, const char *format, int *count)
{
	if (format[*i + 1] == 'd' || format[*i + 1] == 'i')
	{
		int num = va_arg(ptr, int);

		if (num <= INT_MAX && num >= INT_MIN)
		{
			print_num(num, count);
			*i = *i + 1;
		}
		else
			return (-1);
	}
	return (0);
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
		unsigned int num = va_arg(ptr, unsigned int);

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
 * print_hex - print_hex
 * @i: i
 * @ptr: ptr
 * @format: format
 * @count: count
 * Return: int
 */
int print_hex(int *i, va_list ptr, const char *format, int *count)
{
	if (format[*i + 1] == 'X')
	{
		int num = va_arg(ptr, int);

		convert_decimal(num, 16, 1, count, 0);

		*i = *i + 1;
		return (0);
	}

	if (format[*i + 1] == 'x')
	{
		int num = va_arg(ptr, int);

		convert_decimal(num, 16, 0, count, 0);

		*i = *i + 1;
		return (0);
	}
	return (0);
}

/**
 * print_octal - print_octal
 * @i: i
 * @ptr: ptr
 * @format: format
 * @count: count
 * Return: int
 */
int print_octal(int *i, va_list ptr, const char *format, int *count)
{
	if (format[*i + 1] == 'o')
	{
		unsigned int num = va_arg(ptr, unsigned int);

		convert_decimal(num, 8, 0, count, 0);

		*i = *i + 1;
	}
	return (0);
}
