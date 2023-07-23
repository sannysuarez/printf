#include <unistd.h>
#include <stdarg.h>
#include "main.h"

/**
 * _putchar - Write a character to stdout
 * @c: The character to be written
 * Return: On success, 1 is returned. On error, -1 is returned.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _strlen - Calculate the length of a string
 * @str: The input string
 * Return: The length of the string
 */
int _strlen(const char *str)
{
	int len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

/**
 * print_string - Print a string to stdout
 * @str: The input string
 * Return: The number of characters printed
 */
int print_string(const char *str)
{
	int len = _strlen(str);
	return (write(1, str, len));
}

/**
 * print_char - Print a character to stdout
 * @c: The character to be printed
 * Return: 1 (success)
 */
int print_char(char c)
{
	return _putchar(c);
}

/**
 * print_integer - Print an integer to stdout
 * @num: The integer to be printed
 * Return: The number of characters printed
 */
int print_integer(int num)
{
	int count = 0;

	// Handle negative numbers
	if (num < 0)
	{
		count += print_char('-');
		num = -num;
	}

	// Convert the integer to a string and print it
	if (num / 10 != 0)
		count += print_integer(num / 10);

	count += print_char(num % 10 + '0');
	return (count);
}

/**
 * _printf - Produces output according to a format.
 * @format: The format string
 * Return: The number of characters printed (excluding the null byte)
 *
 * Description:
 * This function prints formatted output to stdout. It supports
 * the following conversion specifiers: 'c', 's', 'd', 'i', and '%'.
 * The function returns the total number of characters printed.
 */
int _printf(const char *format, ...)
{
	int i = 0, count = 0;
	char *str_arg;
	int int_arg;
	va_list args;

	va_start(args, format);

	while (format && format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
				case 'c':
					count += print_char(va_arg(args, int));
					break;
				case 's':
					str_arg = va_arg(args, char *);
					if (str_arg == NULL)
						str_arg = "(null)";
					count += print_string(str_arg);
					break;
				case 'd':
				case 'i':
					int_arg = va_arg(args, int);
					count += print_integer(int_arg);
					break;
				case '%':
					count += print_char('%');
					break;
				default:
					count += print_char('%');
					count += print_char(format[i]);
			}
		}
		else
		{
			count += print_char(format[i]);
		}
		i++;
	}

	va_end(args);
	return (count);
}