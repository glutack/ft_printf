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
unsigned int	ft_putnbr(int n)
{
	unsigned int	len;

	len = 0;
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	else if (n < 0)
	{
		ft_putchar('-');
		n = -n;
		len++;
	}
	else if (nb < 10)
	{
		ft_putchar(n + '0');
		len++;
	}
	else
	{
		len += ft_putnbr(n / 10);
		len +=ft_putchar(n % 10);
	}
	return (len);
}

//%u -> num decimal sin signo

//%p -> puntero void * en hexadecimal
//%x -> num hexadecimal en minúscula
//%X -> num hexadecimal en mayúscula
unsigned int	ft_puthex(unsigned long long n, const char *type)
{
	int	len;

	len = 0;
	if (num < 16)
	{
		ft_putchar(type[n]);
		len++;
	}
	else
	{
		len += ft_puthex(n / 16, type);
		len += ft_puthex(n % 16, type);
	}
	return (len);
}

// hay conversión?

int static	ft_isconver(char conver, va_list arg_list)
{
	unsigned int	len;

	len = 0;
	if (conver == 'c')
		len = ft_putchar(va_arg(arg_list, int));
	else if (conver == 's')
		len = ft_putstr(va_arg(arg_list, char *));
	/*else if (conver == 'p')
	{
		len = ft_putstr("0x");
		len += ft_puthex("123456789abcdefg", va_arg(arg_list, int));
	}*/
	else if (conver == 'd' || conver == 'i')
		len = ft_putnbr(va_arg(arg_list, int));
	//else if (conver = 'u')
	else if (conver == 'x' || conver == 'p')
		len = ft_putstr("0x");
		len += ft_puthex("0123456789abcdef", va_arg(arg_list, unsigned int))
	else if (conver == 'X')
	{
		len = ft_putstr("0X");
		len += ft_puthex("0123456789ABCDEF", va_arg(arg_list, unsigned int));
	}
	else if (conver == '%')
		len = ft_putchar('%');
	return (len);
}

// printf
int	ft_printf(char const *arg, ...)
{
	va_list			arg_list;
	unsigned int	i;
	unsigned int	len;

	va_start(arg_list, arg);
	i = -1;
	len = 0;
	while (arg[++i])
	{
		if (arg[i] == '%')
			len += ft_isconver(arg[++i], arg_list);
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
