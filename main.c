#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int count_digit(int nbr)
{
	long	num;
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
		num /= 10;
		count++;
	}
	return (count);
}

char *puthexa(unsigned int num)
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
            ptr[--len] = 55 + stock;
        num /= 16;
    }
    return ptr;
}

// char *putadr(unsigned int num)
// {

// }

int main()
{
    int i = 24089;
    int *pt = &i;
    char *str = puthexa(3107776008);
    printf("i in hex 0x%s\n", str);
    printf("i is %p\n", pt);
    return 0;
}
