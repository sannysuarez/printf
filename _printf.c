#include "main.h"

/**
 * _printf - formatted output conversion and print data.
 * @format: input string.
 *
 * Return: number of chars printed.
 */
int _printf(const char *format, ...)
{
	unsigned int i = 0, lent = 0, ibuf = 0;
	va_list arguments;
	int (*function)(va_list, char *, unsigned int);
	char *buffer;

	va_start(arguments, format), buffer = malloc(sizeof(char) * 1024);
	if (!format || !buffer || (format[i] == '%' && !format[i + 1]))
		return (-1);
	if (!format[i])
		return (0);
	for (i = 0; format && format[i]; i++)
	{
<<<<<<< HEAD
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
=======
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
			{	print_buf(buffer, ibuf), free(buffer), va_end(arguments);
				return (-1);
>>>>>>> 94411da20782702f7e4d5ea9d73be556230dccc8
			}
			else
			{	function = get_print_func(format, i + 1);
				if (function == NULL)
				{
					if (format[i + 1] == ' ' && !format[i + 2])
						return (-1);
					handl_buf(buffer, format[i], ibuf), lent++, i--;
				}
				else
				{
					lent += function(arguments, buffer, ibuf);
					i += ev_print_func(format, i + 1);
				}
			} i++;
		}
		else
			handl_buf(buffer, format[i], ibuf), lent++;
		for (ibuf = lent; ibuf > 1024; ibuf -= 1024)
			;
	}
	print_buf(buffer, ibuf), free(buffer), va_end(arguments);
	return (lent);
}
