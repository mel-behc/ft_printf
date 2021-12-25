#include "ft_printf.h"

void	ft_toupper(char *c)
{
	int i;

	i = 0;
	if (c != NULL)
	{
		while (c[i])
		{
			if (c[i] >= 'a' && c[i] <= 'z')
				c[i] -= 32;
			i++;
		}
	}	
}
