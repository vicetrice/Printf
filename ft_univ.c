#include "ft_printf.h"

void	ft_printstr(char *s)
{
	int	cont;

	cont = 0;
	while (s[cont])
		++cont;
	write(1, s, cont);
}

void	ft_printptr(unsigned long long ptr)
{
	ft_printstr("0x");
	ft_auxptr(ptr);
}

void	ft_printnbr(int n)
{
	ft_auxnbr(n);
}

void	ft_printunsgnd(unsigned int un)
{
	ft_auxunbr(un);
}

void	ft_printhex(unsigned int hex, const char w)
{
	ft_printstr("0x");
	ft_auxhex(hex, w);
}
