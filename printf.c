#include <stdio.h>
#include <stdarg.h>
#include "main.h"

int _printf(const char *format, ...) {
    int count = 0;
    int* arg = (int*)&format + 1;

    while (*format) {
        if (*format == '%') {
            format++;

            // Handle conversion specifiers
            switch (*format) {
                case 'c':
                    putchar((char)(*arg));
                    count++;
                    break;
                case 's':
                    {
                        const char *str = (const char*)(*arg);
                        while (*str) {
                            putchar(*str);
                            count++;
                            str++;
                        }
                    }
                    break;
                case 'd':
                case 'i':
                    {
                        int num = *arg;
                        printf("%d", num);
                        count++;
                    }
                    break;
                case '%':
                    putchar('%');
                    count++;
                    break;
                default:
                    // Unsupported specifier, just print it as is
                    putchar('%');
                    putchar(*format);
                    count += 2;
            }
            arg++; // Move to the next argument
        } else {
            putchar(*format);
            count++;
        }

        format++;
    }

    return count;
}

int main() {
    _printf("Hello, %s! The answer is %d%%. Character: %c\n", "User", 69, 'H');
    _printf("This is a number: %d\n", 43564);
    return 0;
}
