#include <stdarg.h>
#include <unistd.h>
#include "libft.h"

//%s -> un string
int ft_print_str(char *str)
{
    int i;
    
    i = 0;
    while (str[i] != '\0')
    {
        write(1, &str[i], 1);
        i++;
    }
    return (ft_strlen(str));
}

//%x -> num hexadecimal en minúscula
//%X -> num hexadecimal en mayúscula

int ft_print_hex(int num, int upper)
{
    char hex[16];
    int len;

    len = 0;
    if (upper)
        hex = '0123456789ABCDEF';
    else
        hex = '0123456789abcdef';
    if (n > 16)
        ft_print_hex(n / 16, upper);
        write(1, hex[n % 16], 1);
        len++;
    else if (n < 16)
        write(1, hex[n], 1);
        len++;
    return (len);
}

int ft_printf(char const* arg, ...)
{
    va_list list;
    va_start(list, arg);

    int i;

    i = 0;
    while (arg[i] != '\0')
    {
        if (arg[i] == '%')
        {
            i++;
            if (arg[i] == 's')
                ft_print_str(va_arg(list, char *));
            else if (arg[i] == 'x' || arg[i] == 'X')
                ft_print_hex(va_arg(list, int), ft_isalpha(arg[i]));
        }
        else
        {
            write(1, &arg[i], 1)
        } 
        i++;
    }
    va_end(list);
    return ()
}

//%c -> un solo carácter


//%p -> puntero void * en hexadecimal

//%d -> num decimal
int ft_print_dec(int num)
{

}

//%i -> int base 10

//%u -> num decimal sin signo

//%% -> porcentaje
int ft_print_percent()

int main(void)
{
    ft_printf("Hola %s %s", 'limon', 'salchicha');
}