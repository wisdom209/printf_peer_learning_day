#include "main.h"

/**
 * print_Rot13 - print string in Rot13 encryption
 * @i: i
 * @ptr: ptr
 * @format: format
 * @count: count
 *
 * Return: int
 */
int print_Rot13(int *i, va_list ptr, const char *format, int *count)
{
	if (format[*i + 1] == 'R')
	{
		char *src = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
		char *ref = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
		char *s = va_arg(ptr, char *);
		int j = 0, k = 0;

		if (s == NULL)
			s = "(null)";

		while (s[j] != '\0')
		{
			k = 0;

			while (src[k] != '\0')
			{
				if (src[k] == s[j])
				{
					_putchar(ref[k]);
					*count = *count + 1;
					break;
				}
				k++;
			}

			if (s[j] != src[k])
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
 * print_string - print string
 * @i: i
 * @ptr: ptr
 * @format: format
 * @count: count
 *
 * Return: int
 */
int print_string(int *i, va_list ptr, const char *format, int *count)
{
	if (format[*i + 1] == 's')
	{
		char *s = va_arg(ptr, char *);
		int j = 0;

		if (s == NULL)
			s = "(null)";

		while (s[j] != '\0')
		{
			_putchar(s[j]);
			*count = *count + 1;
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
			s = "(null)";

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
			s = "(null)";

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
