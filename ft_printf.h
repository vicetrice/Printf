# ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

void	ft_auxhex(unsigned int numi, const char cap);
void	ft_auxunbr(unsigned int unb);
void	ft_auxnbr(int nb);
void	ft_auxptr(unsigned long long drcton);
int		ft_printf(const char *str, ...);
void	ft_printchar(const char c);
void	ft_printstr(char *s);
void	ft_printnbr(int n);
void	ft_printunsgnd(unsigned int un);
void	ft_printhex(unsigned int num, const char w);
void	ft_printptr(unsigned long long ptr);

#endif
