#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (s != NULL)
	{
		while (s[i])
		{
			write(1, &s[i], 1);
			i++;
		}
	}
}

void	ft_putnbr(int n)
{
	int	signe;

	signe = 1;
	if (n < -9 || n > 9)
		ft_putnbr((int)(n / 10));
	if (n < 0 && n >= -9)
		ft_putchar('-');
	if (n < 0)
		signe = -1;
	ft_putchar((n % 10) * signe + '0');
}


        
static size_t	count_digit(int nbr)
{
	long	num;
	size_t	count;

	num = nbr;
	count = 0;
	if (num <= 0)
	{
		num *= -1;
		count = 1;
	}
	while (num > 0)
	{
		num /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*ptr;
	long	nbr;
	size_t	len;

	ptr = NULL;
	nbr = n;
	if (nbr < 0)
		nbr *= -1;
	len = count_digit(n);
	ptr = (char *)malloc(sizeof(char) * len + 1)
	if (!ptr)
		return (NULL);
	ptr[len] = '\0';
	len--;
	while (nbr > 0)
	{
		ptr[len] = (nbr % 10) + 48;
		nbr /= 10;
		len--;
	}
	if (n < 0)
		ptr[0] = '-';
	if (n == 0)
		ptr[0] = '0';
	return (ptr);
}



