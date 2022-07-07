#include <stdarg.h>
#include <unistd.h>
#include "libft.h"

//%c 
//%% -> porcentaje
unsigned int ft_putchar(char c)
{
    write(1, &c, 1)
    return (1);
}

//%s -> un string
unsigned int ft_putstr(char *str)
{
    unsigned int    i;
    
    i = 0;
    if (str)
    {
        write(1, str, ft_strlen(str));
    }
    return (ft_strlen(str));
}

//%p -> puntero void * en hexadecimal



//%d -> num decimal ??
//%i -> int base 10
unsigned int	ft_putnbr(int nb)
{
    unsigned int    len;
    
    len = 0;
	if (nb == -2147483648)
		write(1, "-2147483648", 11);
        len = 11;
	else if (nb < 0)
	{
		ft_putchar('-');
		ft_putnbr(nb *= -1);
        len++;
	}
	else if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar(nb + '0');
        len++;
    return (len);
}

//%u -> num decimal sin signo



//%x -> num hexadecimal en minúscula
//%X -> num hexadecimal en mayúscula
int ft_puthex(int num, int upper)
{
    char    hex[16];
    unsigned int    len;

    len = 0;
    if (upper)
        hex = '0123456789ABCDEF';
    else
        hex = '0123456789abcdef';
    if (n > 16)
        ft_puthex(n / 16, upper);
        write(1, hex[n % 16], 1);
        len++;
    else if (n < 16)
        write(1, hex[n], 1);
        len++;
    return (len);
}

// hay conversión?

int static ft_isconver(char c, va_list list)
{
    unsigned int    len;

    len = 0;
    if (c == 'c')
        len = ft_putchar(va_arg(list, int));
    else if (c == 's')
        len = ft_putstr(va_arg(list, char *));
    else if (c = 'p')
    else if (c = 'd' || c = 'i')
        len = ft_putnbr(va_arg(list, int));
    //else if (c = 'i')
    else if (c = 'u')
    else if (c == 'x' || arg[i] == 'X')
    {
        if (c == 'x')
            len = ft_putstr("0x");
        else if (c == 'X')
            len = ft_putstr("0X");
        len = ft_puthex(va_arg(list, int), ft_isalpha(arg[i]));
    }
    else if (c = '%')
        len = ft_putchar(va_arg(list, int))
}

// printf
int ft_printf(char const *arg, ...)
{
    va_list list;
    unsigned int    i;
    unsigned int    len;

    va_start(list, arg);
    i = -1;
    len = 0;
    while (arg[++i])
    {
        if (arg[i] == '%')
            len += ft_isconver(str[++i], list)
        else
            len += ft_putchar(arg[i]);
    }
    va_end(list);
    return (len)
}

int main(void)
{
    ft_printf("Hola %s %s", 'limon', 'salchicha');
}