#include "main.h"

/**
 * main - entry
 * Return: int
 */
int main(void)
{
	int a = 0, b = 0;

	a = _printf("%x\n", -9304);
	b =  printf("%x\n", -9304);

	printf("my length = %d, machine length %d\n", a, b);

	return (0);
}

