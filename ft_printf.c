/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valvarad <valvarad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:17:12 by valvarad          #+#    #+#             */
/*   Updated: 2024/03/06 11:45:53 by valvarad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_choices(va_list argument, const char c);

int	ft_printf(char const *str, ...)
{
	int		i;
	va_list	argument;
	int		size;

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
	return (len);
}

int	ft_printchar(const char c)
{
	write(1, &c, 1);
	return (1);
}
/*
#include <stdio.h>
int main()
{
	//int *p;
	int l;
	//int q = 20;
		//p = NULL;

	l = printf("\001\002\007\v\010\f\r\n");
	printf("%d",l);
	m = 	printf("hola loco %X",q);
	printf("%d",m);
}*/
