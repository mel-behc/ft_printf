#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

void	ft_putchar(char c);
void	ft_putstr(char *s);
void	ft_putnbr(int n);
void	ft_uptnbr(unsigned int n);
int     ft_toupper(int c);
int     ft_printf(const char *fmt, ...);

#endif
