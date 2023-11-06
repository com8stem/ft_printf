#include "ft_printf.h"

int	count_digits_unsign(unsigned int num)
{
	int				digits;
	unsigned long	n;

	digits = 0;
	n = (unsigned long)num;
	while (n >= 10)
	{
		n = n / 10;
		digits++;
	}
	return (digits + 1);
}

char	*ft_itoa_unsign(unsigned int n)
{
	int				digits;
	char			*result;
	unsigned long	num;

	num = (unsigned long)n;
	if (n == 0)
		return (ft_strdup("0"));
	digits = count_digits_unsign(n);
	result = (char *)malloc((digits + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	result[digits--] = '\0';
	while (num > 0)
	{
		result[digits--] = num % 10 + '0';
		num = num / 10;
	}
	return (result);
}