/* KurtOS Kernel

(c) Kurt Carre 2019

Licensed under AGPL v3

printf implementation
*/

#include "../stdio.h"
#include <limits.h>
#include <stdbool.h>
#include <stdarg.h>
#include <stdint.h>
#include "../string.h"

void printNumber(int num, int base, bool sign);

static bool print(const char* data, size_t length)
{
    const unsigned char* bytes = (const unsigned char*)data;
    for(size_t i = 0; i < length; i++)
    {
        if(putchar(bytes[i]) == EOF)
            return false;
    }
    return true;
}

int printf(const char* restrict format, ...)
{
    int base = 10;
    bool sign = false;
    int number;
    size_t len;

    va_list parameters;
    va_start(parameters, format);

    int written = 0;

    while(*format != '\0')
    {
        size_t maxrem = INT_MAX - written;

        if(format[0] != '%' || format[1] == '%')
        {
            if(format[0] == '%')
                format++;
            
            size_t amount = 1;
            while(format[amount] && format[amount] != '%')
                amount++;
            
            if(maxrem < amount)
                return -1;
            
            if(!print(format, amount))
                return -1;

            format += amount;
            written += amount;
            continue;
        }

        const char* format_begun_at = format++;

        switch(*format)
        {
            case 'c':
                format++;
                char c = (char) va_arg(parameters, int);
                if(!maxrem)
                    return -1;
                
                if(!print(&c, sizeof(c)))
                    return -1;
                
                written++;
                break;

            case 's':
                format++;
                const char* str = va_arg(parameters, const char*);
                len = strlen(str);
                if(maxrem < len)
                    return -1;
                
                if(!print(str, len))
                    return -1;
                
                written += len;
                break;
            
            case 'i':
            case 'd':
                base = 10;
                number = va_arg(parameters, int);
                sign = true;
                printNumber(number, base, sign);
                format++;
                break;
            
            case 'u':
                base = 10;
                number = va_arg(parameters, int);
                sign = false;
                printNumber(number, base, sign);
                format++;
                break;

            case 'X':
            case 'x':
            case 'p':
                base = 16;
                number = va_arg(parameters, int);
                sign = false;
                print("0x", strlen("0x"));
                printNumber(number, base, sign);
                format++;
                break;

            default:
                format = format_begun_at;
                len = strlen(format);
                if(maxrem < len)
                    return -1;
                
                if(!print(format, len))
                    return -1;
                
                written += len;
                format += len;
                break;
        }
    }

    va_end(parameters);
    return written;
}

const char hexNumbers[] = "0123456789ABCDEF";

void printNumber(int num, int base, bool sign)
{
    char buffer[32];
    int number = num;
    int num_sign = 1;
    int pos = 0;

    if(sign)
    {
        if(number < 0)
        {
            number = -num;
            num_sign = -1;
        }
    }

    do
    {
        uint32_t rem = number % base;
        number /= base;
        buffer[pos++] = hexNumbers[rem];
    } while (number > 0);
    
    if(sign && num_sign < 0)
        buffer[pos++] = '-';

        while(--pos >= 0)
            putchar(buffer[pos]);
}