#include "ft_printf.h"

void	ft_putnbr(int n, int *j)
{
	int	signe;

	signe = 1;
	if (n < -9 || n > 9)
		ft_putnbr((int)(n / 10), j);
	if (n < 0 && n >= -9)
		ft_putchar('-', j);
	if (n < 0)
		signe = -1;
	ft_putchar((n % 10) * signe + '0', j);
}
