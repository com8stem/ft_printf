#include "ft_printf.h"

int	ft_printchar(char c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_printstr(char *src)
{
	int	len;

	len = ft_strlen(src);
	if (len == -1)
	{
		src = "(null)";
		len = 6;
	}
	write (1, src, len);
	return (len);
}

int	ft_printnbr(int num)
{
	char	*str;
	int		len;

	str = ft_itoa(num);
	if (str == NULL)
		return (0);
	len = ft_printstr(str);
	free (str);
	return (len);
}

int	ft_printunsigned(unsigned int num)
{
	char	*str;
	int		len;

	str = ft_itoa_unsign(num);
	if (str == NULL)
		return (0);
	len = ft_printstr(str);
	free (str);
	return (len);
}


int	ft_printpercent(void)
{
	write (1, "%", 1);
	return (1);
}