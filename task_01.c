 #include <unistd.h>
 #include <stdarg.h>
#include "main.h"

 int _putchar(char c);
 int _strlen(const char *str);
int print_string(const char *str);
 int print_char(char c);
 int print_integer(int num);
 int _printf(const char *format, ...);
 int _putchar(char c)
 {
     return (write(1, &c, 1));
 }

 int _strlen(const char *str)
 {
     int len = 0;
     while (str[len] != '\0')
         len++;
     return (len);
 }

 int print_string(const char *str)
 {
     int len = _strlen(str);
     return (write(1, str, len));
 }

 int print_char(char c)
 {
     return _putchar(c);
 }

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
