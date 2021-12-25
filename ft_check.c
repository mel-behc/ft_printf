#include "ft_printf.h"

void ft_check(va_list ptr, char *c, int *j)
{
    char *s;

    if (*c == '%' && *(c + 1) == '%')
        ft_putchar('%', j);
    else if (*(c + 1) == 'd' || *(c + 1) == 'i')
        ft_putnbr(va_arg(ptr, int), j);
    else if (*(c + 1) == 'u')
        ft_uputnbr(va_arg(ptr, unsigned int), j);
    else if (*(c + 1) == 'c')
        ft_putchar(va_arg(ptr, int), j);
    else if (*(c + 1) == 's')
        ft_putstr(va_arg(ptr, char *), j);
    else if (*(c + 1) == 'p' || *(c + 1) == 'x' || *(c + 1) == 'X')
    {
        if (*(c + 1) == 'p')
        {
            s = ft_puthexa(va_arg(ptr, unsigned long), *(c + 1));
            ft_putstr("0x", j);
        }
        else
            s = ft_puthexa(va_arg(ptr, unsigned int), *(c + 1));
        ft_putstr(s, j);
        free(s);
    }
}