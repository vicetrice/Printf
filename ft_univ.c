/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_univ.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valvarad <valvarad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:22:35 by valvarad          #+#    #+#             */
/*   Updated: 2024/03/06 11:45:22 by valvarad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printstr(char *s)
{
	int	cont;

	cont = 0;
	if (s == NULL)
	{
		return (ft_printstr("(null)"));
	}
	while (s[cont])
		++cont;
	write(1, s, cont);
	return (cont);
}

int	ft_printptr(unsigned long long ptr)
{
	int	leni;

	leni = 0;
	leni += ft_printstr("0x");
	ft_auxptr(ptr, &leni);
	return (leni);
}

int	ft_printnbr(int n)
{
	int	axu;

	axu = 0;
	ft_auxnbr(n, &axu);
	return (axu);
}

int	ft_printunsgnd(unsigned int un)
{
	int	j;

	j = 0;
	ft_auxunbr(un, &j);
	return (j);
}

int	ft_printhex(unsigned int hex, const char w)
{
	int	h;

	h = 0;
	ft_auxhex(hex, w, &h);
	return (h);
}
