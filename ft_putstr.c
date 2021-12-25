#include "ft_printf.h"

void	ft_putstr(char *s, int *j)
{
	int	i;

	i = 0;
	if (s != NULL)
	{
		while (s[i])
			ft_putchar(s[i++], j);
	}
	else
		*j += write(1, "(null)", 6);
}
