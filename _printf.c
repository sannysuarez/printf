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
			printed_chars += putchar(format[i]);
		}
		else
		{
			i++;
			switch (format[i])
			{
				case 'c':
					printed_chars += putchar(va_arg(list, int));
					break;
				case 's':
					printed_chars += print_string(va_arg(list, int));
					break;
				default:
					printed_chars += putchar('%');
					printed_chars += putchar(format[i]);
					break;
			}
		}
	}

	va_end(list);

	return (printed_chars);
}
