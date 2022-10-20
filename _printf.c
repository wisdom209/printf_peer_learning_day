#include "main.h"

/**
 * _printf - printf
 * @format: fomat
 *
 * Return: int
 */
int _printf(const char *format, ...)
{
	int i = 0, count = 0, ret = 0;
	va_list ptr;

	va_start(ptr, format);

	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
			count++;
		}
		else
		{
			ret = print_string(&i, ptr, format, &count);
			ret = print_char(&i, ptr, format, &count);
			ret = print_digits(&i, ptr, format, &count);
			ret = print_percent(&i, format, &count);
			ret = print_unsigned_digits(&i, ptr, format, &count);
			ret = print_binary(&i, ptr, format, &count);
			ret = print_hex(&i, ptr, format, &count);
			ret = print_octal(&i, ptr, format, &count);
			ret = print_ptr(&i, ptr, format, &count);
			ret = print_non_printable(&i, ptr, format, &count);
			ret = print_rev(&i, ptr, format, &count);
			ret = print_Rot13(&i, ptr, format, &count);

			if (ret == -1)
				return (-1);
		}

		i++;
	}
	return (count);
}


