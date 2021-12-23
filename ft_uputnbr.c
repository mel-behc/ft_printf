#include <ft_printf.h>

void	ft_uputnbr(unsigned int n)
{
	if (n < 0 || n > 9)
		ft_putnbr((int)(n / 10));
	ft_putchar((n % 10) + '0');
}
