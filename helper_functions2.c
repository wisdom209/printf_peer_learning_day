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
			return (-1);

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

		j++;
	}

	*i = *i + 1;

	return (0);
}
