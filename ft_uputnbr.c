#include "ft_printf.h"

void	ft_uputnbr(unsigned int n, int *j)
{
	if (n < 0 || n > 9)
		ft_uputnbr((int)(n / 10), j);
	ft_putchar((n % 10) + '0', j);
}
