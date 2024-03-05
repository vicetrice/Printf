# ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

void	ft_auxhex(unsigned int numi, const char cap, int *l);
void	ft_auxunbr(unsigned int unb, int *k);
void	ft_auxnbr(int nb, int *contu);
void	ft_auxptr(unsigned long long drcton, int *coun);
int		ft_printf(const char *str, ...);
int	ft_printchar(const char c);
int	ft_printstr(char *s);
int	ft_printnbr(int n);
int	ft_printunsgnd(unsigned int un);
int	ft_printhex(unsigned int num, const char w);
int	ft_printptr(unsigned long long ptr);

#endif
