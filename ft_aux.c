#include "ft_printf.h"

void	ft_auxptr(unsigned long long drcton)
{
	if (drcton >= 16)
	{
		ft_auxptr(drcton / 16);
		drcton %= 16;
	}
	if (drcton < 10)
		ft_printchar(drcton + '0');
	else if (drcton >= 10)
		ft_printchar(drcton + 'a' - 10);
}

void	ft_auxnbr(int nb)
{
	if (nb == -2147483648)
	{
		ft_printchar('-');
		ft_printchar('2');
		nb = 147483648;
	}
	if (nb < 0)
	{
		ft_printchar('-');
		nb *= -1;
	}
	if (nb >= 10)
	{
		ft_auxnbr(nb / 10);
		ft_auxnbr(nb % 10);
	}
	else
	{
		ft_printchar(nb + '0');
	}
}

void	ft_auxunbr(unsigned int unb)
{
	if (unb >= 10)
	{
		ft_auxunbr(unb / 10);
		ft_auxunbr(unb % 10);
	}
	else
	{
		ft_printchar(unb + '0');
	}
}

void	ft_auxhex(unsigned int numi, const char cap)
{
	if (numi >= 16)
	{
		ft_auxhex(numi / 16, cap);
		numi %= 16;
	}
	if (numi < 10)
		ft_printchar(numi + '0');
	else if (numi >= 10 && cap == 'x')
		ft_printchar(numi + 'a' - 10);
	else if (numi >= 10 && cap == 'X')
		ft_printchar(numi + 'A' - 10);
}
