#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - main function to print in console
 * @format: array to print and check type
 * Return: count of characters printed
 **/
int _printf(const char *format, ...)
{
    int count = 0;
    va_list args;
    
    if (format == NULL)
    {
        return (-1);
    }
    
    va_start(args, format);
    while (*format)
    {
        if (*format == '%')
        {
            format++;
            switch (*format)
            {
                case 'c':
                {
                    char c = va_arg(args, int);
                    count += printf("%c", c);
                    break;
                }
                case 's':
                {
                    char *s = va_arg(args, char *);
                    count += printf("%s", s);
                    break;
                }
                case '%':
                {
                    count += printf("%%", *format);
                    break;
                }
                case 'd':
                case 'i':
                {
                    int num = va_arg(args, int);
                    count += printf("%d", num);
                    break;
                }
                case 'u':
                {
                    unsigned int num = va_arg(args, unsigned int);
                    count += printf("%u", num);
                    break;
                }
                case 'o':
                {
                    unsigned int num = va_arg(args, unsigned int);
                    count += printf("%o", num);
                    break;
                }
                case 'x':
                {
                    unsigned int num = va_arg(args, unsigned int);
                    count += printf("%x", num);
                    break;
                }
                case 'X':
                {
                    unsigned int num = va_arg(args, unsigned int);
                    count += printf("%X", num);
                    break;
                }
                case 'p':
                {
                    void *ptr = va_arg(args, void *);
                    count += printf("%p", ptr);
                    break;
                }
                default:
                {
                    count += printf("%%%c", *format);
                    break;
                }
            }
        }
        else
        {
            count += printf("%c", *format);
        }
        format++;
    }
    
    va_end(args);
    return count;
}
