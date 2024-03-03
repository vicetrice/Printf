#include "ft_printf.h"

void	ft_choices(va_list argument, const char c);

int	ft_printf(char const *str, ...)
{
	int		i;
	va_list	argument;

	i = 0;
	va_start(argument, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			ft_choices(argument, str[++i]);
		}
		else
			write(1, &str[i], 1);
		++i;
	}
	return (0);
}

void	ft_choices(va_list argument, const char c)
{
	if (c == 'c')
		ft_printchar(va_arg(argument, const int));
	else if (c == 's')
		ft_printstr(va_arg(argument, char *));
	else if (c == 'p')
		ft_printptr(va_arg(argument, unsigned long long));
	else if (c == 'd' || c == 'i')
		ft_printnbr(va_arg(argument, int));
	else if (c == 'u')
		ft_printunsgnd(va_arg(argument, unsigned int));
	else if (c == 'x' || c == 'X')
		ft_printhex(va_arg(argument, unsigned int), c);
	else
		ft_printchar(c);
}

void	ft_printchar(const char c)
{
	write(1, &c, 1);
}
/*
int main()
{
	int *p = NULL;
	unsigned l = 1245125;

	ft_printf("direccion puntero en decimal y hex %p,\n num : %x , %X ", p,l,l);
}*/
