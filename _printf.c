#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

int _printf(const char *format, ...) {
    va_list args;
    int count = 0;

    va_start(args, format);

    while (*format != '\0') {
        if (*format == '%') {
            format++;

            switch (*format) {
                case 'c':
                    {
                        char c = va_arg(args, int);
                        putchar(c);
                        count++;
                    }
                    break;
                case 's':
                    {
                        char *str = va_arg(args, char *);
                        fputs(str, stdout);
                        count += strlen(str);
                    }
                    break;
                case '%':
                    {
                        putchar('%');
                        count++;
                    }
                    break;
                default:
                    {
                        putchar('%');
                        putchar(*format);
                        count += 2;
                    }
                    break;
            }
        }
        else {
            putchar(*format);
            count++;
        }

        format++;
    }

    va_end(args);

    return count;
}
