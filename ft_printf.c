#include "ft_printf.h"
#include <stdio.h>

int	ft_choices(va_list argument, const char c);

int	ft_printf(char const *str, ...)
{
	int		i;
	va_list	argument;
	int size;

	i = 0;
	size = 0;
	va_start(argument, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			size += ft_choices(argument, str[++i]);
		}
		else
		{
			write(1, &str[i], 1);
			++size;
		}
		++i;
	}	
	return (size);
}

int	ft_choices(va_list argument, const char c)
{
	int	len;
	if (c == 'c')
		len = ft_printchar(va_arg(argument, const int));
	else if (c == 's')
		len = ft_printstr(va_arg(argument, char *));
	else if (c == 'p')
		len = ft_printptr(va_arg(argument, unsigned long long));
	else if (c == 'd' || c == 'i')
		len = ft_printnbr(va_arg(argument, int));
	else if (c == 'u')
		len = ft_printunsgnd(va_arg(argument, unsigned int));
	else if (c == 'x' || c == 'X')
		len = ft_printhex(va_arg(argument, unsigned int), c);
	else
		len = ft_printchar(c);
	return(len);
}

int	ft_printchar(const char c)
{
	write(1, &c, 1);
	return (1);
}

#include <stdlib.h>

int main(int argc, char *argv[])
{
	int *p;
	int l,m;
	int q = atoi(argv[1]);
	p = NULL;

	l = ft_printf("hola loco %X", q);
	printf("%d",l);
	m = 	printf("hola loco %X",q);
	printf("%d",m);
}
