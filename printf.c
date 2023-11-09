#include <stdio.h>
#include <stdarg.h>

/**
 * print_char - Prints a character and updates the count
 * @c: Character to print
 * @count: Pointer to the count variable
 */
void print_char(char c, int *count)
{
	*count += printf("%c", c);
}

/**
 * print_string - Prints a string and updates the count
 * @s: String to print
 * @count: Pointer to the count variable
 */
void print_string(char *s, int *count)
{
	if (s)
		*count += printf("%s", s);
	else
		*count += printf("(null)");
}

/**
 * print_number - Prints a number and updates the count
 * @num: Number to print
 * @count: Pointer to the count variable
 */
void print_number(int num, int *count)
{
	*count += printf("%d", num);
}

/**
 * _printf - Main function to print formatted output
 * @format: Format string
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					print_char(va_arg(args, int), &count);
					break;
				case 's':
					print_string(va_arg(args, char *), &count);
					break;
				case 'd':
				case 'i':
					print_number(va_arg(args, int), &count);
					break;
				default:
					count += printf("%%%c", *format);
					break;
			}
		}
		else
		{
			print_char(*format, &count);
		}
		format++;
	}

	va_end(args);
	return count;
}
