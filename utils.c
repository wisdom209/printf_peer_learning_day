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
 * convert_decimal - converts to given base
 * @num: num to convert
 * @base: base to convert to
 * @flag_uppercasehex: uppercase or lowercase hex values
 * @count: length of string
 * @isPtr: ptr
 *
 * Return: int
 */
int convert_decimal(unsigned long int num, int base, int flag_uppercasehex,
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

		do {
			buffer[i] = lowerValues[num % base];
			num = num / base;
			i++;
		} while (num != 0);
	}
	else
	{
		do {
			if (flag_uppercasehex == 1)
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

	return (0);
}

/**
 * print_num - prints a number
 * @num: number
 * @count: length
 *
 * Return: int
 */
int print_num(long num, int *count)
{
	int *ptr;
	int i = 0, j = 0;
	long m = 0;

	if (num < 0)
	{
		_putchar('-');
		*count = *count + 1;
		num = num * -1;
	}

	m = num;

	while (m != 0)
	{
		m = m / 10;
		i++;
	}

	m = num;
	ptr = malloc(sizeof(int) * i);

	if (ptr == NULL)
		return (-1);

	for (j = 0; j < i; j++)
	{
		ptr[j] = m % 10;
		m = m / 10;
	}

	for (j = i - 1; j >= 0; j--)
	{
		_putchar(ptr[j] + '0');
		*count = *count + 1;
	}

	free(ptr);
	return (0);
}
