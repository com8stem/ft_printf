#include "ft_printf.h"

int	ft_checksign(va_list args, char sign)
{
	int	print_len;

	print_len = 0;
	if (sign == 'c')
		print_len = print_len + ft_printchar(va_arg(args, int));
	else if (sign == 's')
		print_len = print_len + ft_printstr (va_arg(args, char *));
	else if (sign == 'p')
		print_len = print_len + ft_printaddress (va_arg(args, void *));
	else if (sign == 'd')
		print_len = print_len + ft_printnbr (va_arg(args, int));
	else if (sign == 'i')
		print_len = print_len + ft_printnbr (va_arg(args, int));
	else if (sign == 'u')
		print_len = print_len + ft_printunsigned (va_arg(args, unsigned int));
	else if (sign == 'x')
		print_len = print_len
			+ ft_printhex_sorl (va_arg(args, unsigned int), sign);
	else if (sign == 'X')
		print_len = print_len
			+ ft_printhex_sorl (va_arg(args, unsigned int), sign);
	else if (sign == '%')
		print_len = print_len + ft_printpercent ();
	return (print_len);
}

int	ft_printf(const char *src, ...)
{
	va_list	args;
	int		print_len;
	int		i;

	print_len = 0;
	i = 0;
	va_start (args, src);
	while (src[i] != '\0')
	{
		if (src[i] == '%')
		{
			print_len = print_len + ft_checksign(args, src[i + 1]);
			i = i + 2;
		}
		else
		{
			print_len = print_len + ft_printchar(src[i]);
			i++;
		}
	}
	va_end (args);
	return (print_len);
}
