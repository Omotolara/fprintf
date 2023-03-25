#include "main.h"

/**
 * _printf- produces formatted output
 * @format: the format.
 * Return: printed chars.
 */
int _printf(const char *format, ...)
{
	va_list args;

	va_start(args, format);

	int count = 0;

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == '%')
			{
				putchar('%');
				count++
			}
			else if (*format == 'c')
			{
				char c = va_arg(args, int);

				putchar(c);
				count++;
			}
			else if (*format == 's')
			{
				char *s = va_args(args, char *);

				fputs(s, stdout);
				count += strlen(s);
			}
		}
		else
		{
			putchar(*format);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}
