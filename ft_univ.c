#include "ft_printf.h"

int	ft_printstr(char *s)
{
	int	cont;

	cont = 0;
	while (s[cont])
		++cont;
	write(1, s, cont);
	return(cont);
}

int	ft_printptr(unsigned long long ptr)
{
	int	leni;
	
	leni = 0;
	ft_printstr("0x");
	ft_auxptr(ptr, &leni);
	return (leni);
}

int	ft_printnbr(int n)
{
	int axu;

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
