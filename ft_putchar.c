#include "ft_printf.h"

void	ft_putchar(char c, int *j)
{
	*j += write(1, &c, 1);
}
