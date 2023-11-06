#include "ft_printf.h"

int	ft_hex_len(unsigned long long address)
{
	int	len;

	len = 1;
	while (address >= 16)
	{
		address = address / 16;
		len++;
	}
	return (len);
}

int	ft_printhex_num(unsigned int num, char *base)
{
	if (num >= 16)
		ft_printhex_num(num / 16, base);
	write (1, &base[num % 16], 1);
	return (ft_hex_len(num));
}

int	ft_printhex_address(unsigned long long address, char *base)
{
	if (address >= 16)
		ft_printhex_address(address / 16, base);
	write (1, &base[address % 16], 1);
	return (ft_hex_len(address));
}

int	ft_printaddress(void *point)
{
	unsigned long long	address;
	int					len;

	address = (unsigned long long)point;
	write (1, "0x", 2);
	len = 2;
	len = len + ft_printhex_address(address, "0123456789abcdef");
	return (len);
}

int	ft_printhex_sorl(unsigned int num, char sign)
{
	int	len;

	len = 0;
	if (sign == 'x')
		len = ft_printhex_num(num, "0123456789abcdef");
	else if (sign == 'X')
		len = ft_printhex_num(num, "0123456789ABCDEF");
	return (len);
}