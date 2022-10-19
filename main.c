#include "main.h"

/**
 * main - entry
 * Return: int
 */
int main(void)
{
	int a = 0, b = 0;

	a = _printf("%R\n", "Best School");
	b =  printf("%s\n", "Best School");

	printf("my length = %d, machine length %d\n", a, b);

	return (0);
}

