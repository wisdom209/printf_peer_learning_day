#include "main.h"

/**
 * convert_decimal - converts to given base
 * @num: num to convert
 * @base: base to convert to
 * @flag: upper or lower
 * @count: length of string
 * @isPtr: ptr
 *
 * Return: int
 */
int convert_decimal(unsigned long int num, int base, int flag,
					int *count, int isPtr)
{
	char upperValues[] = "0123456789ABCDEF";
	char lowerValues[] = "0123456789abcdef";
	char buffer[50];
	int i = 0, j = 0;
	unsigned int a = (unsigned int)num;

	if (isPtr)
	{
		_putchar('0');
		_putchar('x');
		*count = *count + 2;

		do
		{
			buffer[i] = lowerValues[num % base];
			num = num / base;
			i++;
		} while (num != 0);
	}
	else
	{
		do
		{
			if (flag == 1)
				buffer[i] = upperValues[a % base];
			else
				buffer[i] = lowerValues[a % base];
			a = a / base;
			i++;
		} while (a != 0);
	}

	buffer[i] = '\0';
	for (j = i - 1; j >= 0; j--)
	{
		_putchar(buffer[j]);
		*count = *count + 1;
	}
	if (flag)
		return (1);
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

/**
 * print_non_printable - print_non_printable
 * @i: i
 * @ptr: ptr
 * @format: format
 * @count: count
 * Return: int
 */
int print_non_printable(int *i, va_list ptr, const char *format, int *count)
{
	if (format[*i + 1] == 'S')
	{
		char *s = va_arg(ptr, char *);
		int j = 0;

		if (s == NULL)
			return (-1);

		while (s[j] != '\0')
		{
			if ((s[j] >= 0 && s[j] <= 32) || s[j] >= 127)
			{
				if (s[j] < 0)
					s[j] = s[j] * -1;

				_putchar('\\');
				_putchar('x');
				if (s[j] >= 0 && s[j] <= 15)
				{
					_putchar('0');
					*count = *count + 1;
				}
				convert_decimal(s[j], 16, 1, count, 0);
			}
			else
			{
				_putchar(s[j]);
				*count = *count + 1;
			}

			j++;
		}
		*i = *i + 1;
	}
	return (0);
}

/**
 * print_rev - print reverse
 * @i: i
 * @ptr: ptr
 * @format: format
 * @count: count
 *
 * Return: int
 */
int print_rev(int *i, va_list ptr, const char *format, int *count)
{
	if (format[*i + 1] == 'r')
	{
		char *s = va_arg(ptr, char *);
		int j = 0, k = 0;

		if (s == NULL)
			return (-1);

		while (s[k] != '\0')
			k++;

		for (j = k - 1; j >= 0; j--)
		{
			_putchar(s[j]);
			*count = *count + 1;
		}

		*i = *i + 1;
	}
	return (0);
}
