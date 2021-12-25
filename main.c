#include <stdio.h>
#include "ft_printf.h"
#include <limits.h>
// int ft_printf(const char *fmt, ...)
// {
//     char    *s;
//     int i;
//     int j;

//     va_list arg;
//     va_start(arg, fmt);
//     i = 0;
//     j = 0;
//     while (fmt[i] != '\0')
//     {
//         if (fmt[i] != '%')
//             ft_putchar(fmt[i], &j);
//         else
//         {
//             ft_check(arg, (char *)&fmt[i], &j);
//             i++;
//         }
//         i++;
//     }
//     va_end (arg);
//     return j;
// }

int main()
{
    // long long i = ;
    // char s = '\0';
    // int *d = &i;
    ft_printf("%p\n", LONG_MAX);
    // int a = ft_printf("%d\n", i);
    // int b = printf("%d\n", i);
    // printf(" %lu\n", (unsigned long)LONG_MAX);
    // s = ft_puthexa(-2);
    return 0;
}
