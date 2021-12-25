#include "ft_printf.h"

static int count_digit(unsigned long nbr)
{
	unsigned long	num;
	int     count;

	num = nbr;
	count = 0;
	if (num == 0)
		count = 1;
	while (num > 0)
	{
		num /= 16;
		count++;
	}
	return (count);
}

char *ft_puthexa(unsigned long num, char c)
{
    unsigned long    stock;
    char    *ptr;
    int     len;

    len = count_digit(num);
    ptr = (char *)malloc(sizeof(char) * len + 1);
    if (!ptr)
        return NULL;
    ptr[len] = '\0';
    ptr[0] = '0';
    while (num > 0 && len > 0)
    {
        stock = num % 16;
        if (stock < 10)
            ptr[--len] = 48 + stock;
        else
            ptr[--len] = 87 + stock;
        num /= 16;
    }
    if (c == 'X')
        ft_toupper(ptr);
    return ptr;
}
