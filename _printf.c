#include "main.h"

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int i, printed_chars = 0;
	va_list list;

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			printed_chars += _putchar(format[i]);
		}
		else
		{
			i++; // Move past the '%'
			switch (format[i])
			{
				case 'c':
					printed_chars += _putchar(va_arg(list, int));
					break;
				case 's':
					printed_chars += print_string(va_arg(list, char *)); // Fixed the function call
					break;
				default:
					printed_chars += _putchar('%');
					printed_chars += _putchar(format[i]);
					break;
			}
		}
	}

	va_end(list);

	return (printed_chars);
}
