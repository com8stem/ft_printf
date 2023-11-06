#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *src, ...);
int		ft_checksign(va_list args, char sign);
int		ft_printhex(unsigned long long address, char *base);
int		ft_printaddress(void *point);
int		ft_printhex_sorl(unsigned int num, char sign);
int		ft_printchar(char c);
int		ft_printstr(char *src);
int		ft_printnbr(int num);
int		ft_printunsigned(unsigned int num);
int		ft_printpercent(void);
size_t	ft_strlen(const char *s);
char	*ft_itoa(int n);
char	*ft_itoa_unsign(unsigned int n);
char	*ft_strdup(const char *s1);

#endif