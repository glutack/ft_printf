/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irmoreno <irmoreno@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 16:50:05 by irmoreno          #+#    #+#             */
/*   Updated: 2022/07/12 19:19:28 by irmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}

size_t	ft_strlen(const char *s)
{	
	unsigned int	len;

	len = 0;
	while (*s++)
		len++;
	return (len);
}

//%c 
//%% -> porcentaje
unsigned int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

//%s -> un string
unsigned int	ft_putstr(char *str)
{
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	else
		write(1, str, ftstrlen(str));
	return (ft_strlen(str));
}

//%p -> puntero void * en hexadecimal

//%d -> num decimal ??
//%i -> int base 10
unsigned int	ft_putnbr(int nb)
{
	unsigned int	len;

	len = 0;
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		len = 11;
	}
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
	{
		ft_putchar(nb + '0');
		len++;
	}
	return (len);
}

//%u -> num decimal sin signo


//%x -> num hexadecimal en minúscula
//%X -> num hexadecimal en mayúscula
int	ft_puthex(int num, int upper)
{
	char			*hex;
	unsigned int	len;

	len = 0;
	if (upper)
		hex = "0123456789ABCDEF";
	else
		hex = "0123456789abcdef";
	if (num > 16)
	{
		ft_puthex(num / 16, upper);
		write(1, &hex[num % 16], 1);
		len++;
	}
	else if (num < 16)
	{
		write(1, &hex[num], 1);
		len++;
	}
	return (len);
}

// hay conversión?

int static	ft_isconver(char c, va_list list)
{
	unsigned int	len;

	len = 0;
	if (c == 'c')
		len = ft_putchar(va_arg(list, int));
	else if (c == 's')
		len = ft_putstr(va_arg(list, char *));
	else if (c = 'p')
	{
		len = ft_putstr("0x");
		len += ft_puthex(va_arg(list. int), ft_isalpha(c));
	}
	else if (c == 'd' || c == 'i')
		len = ft_putnbr(va_arg(list, int));
	//else if (c = 'u')
	else if (c == 'x' || c == 'X')
	{
		if (c == 'x')
			len = ft_putstr("0x");
		else if (c == 'X')
			len = ft_putstr("0X");
			len += ft_puthex(va_arg(list, int), ft_isalpha(c));
	}
	else if (c == '%')
		len = ft_putchar('%');
	return (len);
}

// printf
int	ft_printf(char const *arg, ...)
{
	va_list			list;
	unsigned int	i;
	unsigned int	len;

	va_start(list, arg);
	i = -1;
	len = 0;
	while (arg[++i])
	{
		if (arg[i] == '%')
			len += ft_isconver(arg[++i], list);
		else
			len += ft_putchar(arg[i]);
	}
	va_end(list);
	return (len);
}
