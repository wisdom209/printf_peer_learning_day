#ifndef _main_h_
#define _main_h_
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <stdint.h>
#include <ctype.h>

int _printf(const char *format, ...);
int _putchar(char c);
int print_string(int *i, va_list ptr, const char *format, int *count);
int print_char(int *i, va_list ptr, const char *format, int *count);
int print_rev(int *i, va_list ptr, const char *format, int *count);
int print_Rot13(int *i, va_list ptr, const char *format, int *count);
int print_digits(int *i, va_list ptr, const char *format, int *count);
int print_unsigned_digits(int *i, va_list ptr, const char *format, int *count);
int print_non_printable(int *i, va_list ptr, const char *format, int *count);
int print_binary(int *i, va_list ptr, const char *format, int *count);
int print_octal(int *i, va_list ptr, const char *format, int *count);
int print_hex(int *i, va_list ptr, const char *format, int *count);
int print_ptr(int *i, va_list ptr, const char *format, int *count);
int print_num(long num, int *count);
int print_percent(int *i, const char *format, int *count);
int convert_decimal(unsigned long int num, int base, int flag_uppercase_hex,
					int *count, int isPtr);
#endif
