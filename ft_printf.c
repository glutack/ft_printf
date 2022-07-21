/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irmoreno <irmoreno@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 16:50:05 by irmoreno          #+#    #+#             */
/*   Updated: 2022/07/21 20:56:25 by irmoreno         ###   ########.fr       */
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
		write(1, str, ft_strlen(str));
	return (ft_strlen(str));
}

//%d -> num decimal ??
//%i -> int base 10
unsigned int	ft_putnbr(int num)
{
	unsigned int	len;
	long	n;

	len = 0;
	n = num;	
	if (n < 0)
	{
		ft_putchar('-');
		ft_putnbr(n *= -1);
		len++;
	}
	else if (n > 9)
	{
		len += ft_putnbr(n / 10);
		ft_putchar((n % 10) + '0');
		len++;
	}
	else
	{
		
		 58     unft_putchar(n + '0');
		len++;
	}
	return (len);
}

//%u -> num decimal sin signo

//%p -> puntero void * en hexadecimal
//%x -> num hexadecimal en minúscula
//%X -> num hexadecimal en mayúscula
int	ft_puthex(int num, int upper)
{
	char			*hex;
	unsigned int	len;

	len = 0;
	if (num == 0)
	{
		write(1, "000000000", 9);
		return (9);
	}
	if (upper == 1)
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
	else if (c == 'p')
	{
		len = ft_putstr("0x");
		len += ft_puthex(va_arg(list, int), ft_isalpha(c));
	}
	else if (c == 'd' || c == 'i')
		len = ft_putnbr(va_arg(list, int));
	//else if (c = 'u')
	else if (c == 'x')
		len = ft_putstr("0x");
	else if (c == 'X')
	{
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

int	main()
{
	ft_printf(-10);
}
