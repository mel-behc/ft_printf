#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

void	ft_putchar(char c, int *j);
void	ft_putstr(char *s, int *j);
void	ft_putnbr(int n, int *j);
void	ft_uputnbr(unsigned int n, int *j);
char    *ft_puthexa(unsigned long num, char c);
void    ft_toupper(char *c);
void    ft_check(va_list ptr, char *c, int *j);
int     ft_printf(const char *fmt, ...);

#endif
