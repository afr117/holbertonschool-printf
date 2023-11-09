#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - Custom printf function
 * @format: Format string
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;
    const char *ptr;
    char c;
    char *str;

    va_start(args, format);
    ptr = format;

    while (ptr && *ptr)
    {
        if (*ptr == '%')
        {
            ptr++;
            switch (*ptr)
            {
                case 'c':
                    c = va_arg(args, int);
                    write(1, &c, 1);
                    count++;
                    break;
                case 's':
                    str = va_arg(args, char *);
                    if (str)
                    {
                        while (*str)
                        {
                            write(1, str, 1);
                            str++;
                            count++;
                        }
                    }
                    else
                    {
                        write(1, "(null)", 6);
                        count += 6;
                    }
                    break;
                case '%':
                    write(1, "%", 1);
                    count++;
		    if (*(ptr + 1) != '\0') {
			write(1, ptr + 1, 1);
			count++;
		    }
                    break;
                default:
                    write(1, "%", 1);
                    write(1, ptr, 1);
                    count += 2;
                    break;
            }
        }
        else
        {
            write(1, ptr, 1);
            count++;
        }
        ptr++;
    }

    va_end(args);
    return count;
}

