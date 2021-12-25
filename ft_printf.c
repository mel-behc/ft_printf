#include "ft_printf.h"

int ft_printf(const char *fmt, ...)
{
    int i;
    int j;

    va_list arg;
    va_start(arg, fmt);
    i = 0;
    j = 0;
    while (fmt[i] != '\0')
    {
        if (fmt[i] != '%')
            ft_putchar(fmt[i], &j);
        else
        {
            ft_check(arg, (char *)&fmt[i], &j);
            i++;
        }
        i++;
    }
    va_end (arg);
    return j;
}