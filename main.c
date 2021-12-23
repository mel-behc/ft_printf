#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>


void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_toupper(int c)
{
    if (c >= 97 && c <= 122)
		c -= 32;
	return (c);
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

void	ft_uputnbr(unsigned int n)
{
	if (n < 0 || n > 9)
		ft_putnbr((int)(n / 10));
	ft_putchar((n % 10) + '0');
}

int	ft_strlen(const char *s)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int count_digit(unsigned int nbr)
{
	unsigned long	num;
	int     count;

	num = nbr;
	count = 0;
	if (num <= 0)
	{
		num *= -1;
		count = 1;
	}
	while (num > 0)
	{
		num /= 16;
		count++;
	}
	return (count);
}

char *ft_puthexa(unsigned int num)
{
    long    stock;
    char    *ptr;
    int     len;

    len = count_digit(num);
    ptr = (char *)malloc(sizeof(char) * len + 1);
    if (!ptr)
        return NULL;
    ptr[len] = '\0';
    while (num > 0 && len > 0)
    {
        stock = num % 16;
        if (stock < 10)
            ptr[--len] = 48 + stock;
        else
            ptr[--len] = 87 + stock;
        num /= 16;
    }
    return ptr;
}

int ft_printf(const char *fmt, ...)
{
    char    *str;
    char    *s;
    int i;
    int j;

    va_list arg;
    va_start(arg, fmt);
    str = (char *)fmt;
    i = 0;
    j = 0;
    while (str[i] != '\0')
    {
        if (str[i] != '%')
            ft_putchar(str[i]);
        else if (str[i] == '%' && str[i + 1] == '%')
        {
            ft_putchar('%');
            i = i + 1;
        }
        else
        {
            if (str[i + 1] == 'd' || str[i + 1] == 'i')
                ft_putnbr(va_arg(arg, int));
            else if(str[i + 1] == 'u')
                ft_uputnbr(va_arg(arg, unsigned int));
            else if (str[i + 1] == 'c')
                ft_putchar(va_arg(arg, int));
            else if (str[i + 1] == 's')
                ft_putstr(va_arg(arg, char *));
            else if (str[i + 1] == 'p')
            {
                s = ft_puthexa(va_arg(arg, unsigned int));
                ft_putstr(s);
            }
            else if (str[i + 1] == 'x' || str[i + 1] == 'X')
            {
                s = ft_puthexa(va_arg(arg, unsigned int));
                if (str[i + 1] != 'x')
                {
                    while (s[j])
                    {
                        s[j] = ft_toupper(s[j]);
                        ft_putchar(s[j++]);
                    }    
                }
                else
                    ft_putstr(s);
            }
            i++;
        }
        i++;
    }
    va_end (arg);
    return i;
}

int main()
{
    int i = 234;
    char *s;
    // int *d = &i;
    int a = ft_printf("the number is %%%%%p and something\n", &i);
    printf("the number is %%%%%p and something\n", &i);
    // s = ft_puthexa(-2);
    return 0;
}
