#include "ft_printf.h"

void	ft_auxptr(unsigned long long drcton, int *coun)
{
	if (drcton >= 16)
	{
		ft_auxptr(drcton / 16, coun);
		drcton %= 16;
	}
	if (drcton < 10)
		(*coun) += ft_printchar(drcton + '0');
	else if (drcton >= 10)
		(*coun) += ft_printchar(drcton + 'a' - 10);

}

void	ft_auxnbr(int nb, int *contu)
{
	if (nb == -2147483648)
	{
		(*contu) += ft_printchar('-');
		(*contu) += ft_printchar('2');
		nb = 147483648;
	}
	if (nb < 0)
	{
		(*contu) += ft_printchar('-');
		nb *= -1;
	}
	if (nb >= 10)
	{
		ft_auxnbr(nb / 10, contu);
		ft_auxnbr(nb % 10, contu);
	}
	else
	{
		(*contu) += ft_printchar(nb + '0');
	}
}

void	ft_auxunbr(unsigned int unb, int *k)
{
	if (unb >= 10)
	{
		ft_auxunbr(unb / 10, k);
		ft_auxunbr(unb % 10, k);
	}
	else
	{
		(*k) += ft_printchar(unb + '0');
	}
}

void	ft_auxhex(unsigned int numi, const char cap, int *l)
{
	if (numi >= 16)
	{
		ft_auxhex(numi / 16, cap, l);
		numi %= 16;
	}
	if (numi < 10)
		(*l) += ft_printchar(numi + '0');
	else if (numi >= 10 && cap == 'x')
		(*l) += ft_printchar(numi + 'a' - 10);
	else if (numi >= 10 && cap == 'X')
		(*l) += ft_printchar(numi + 'A' - 10);
}
