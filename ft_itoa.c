#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	if (s == NULL)
		return (-1);
	while (*s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

char	*ft_strcpy(char *dest, const char *src)
{
	char	*dest_origin;

	dest_origin = dest;
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (dest_origin);
}

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*dest;

	len = ft_strlen(s1);
	dest = (char *)malloc(len + 1);
	if (s1 == NULL)
	{
		return (NULL);
	}
	if (dest == NULL)
	{
		return (NULL);
	}
	ft_strcpy(dest, s1);
	return (dest);
}


int	count_digits(int num)
{
	int		digits;
	long	n;

	digits = 0;
	n = (long)num;
	if (num < 0)
	{
		n = -n;
		digits++;
	}
	while (n >= 10)
	{
		n = n / 10;
		digits++;
	}
	return (digits + 1);
}

char	*ft_itoa(int n)
{
	int		digits;
	char	*result;
	long	num;

	num = (long)n;
	if (n == 0)
		return (ft_strdup("0"));
	digits = count_digits(n);
	if (n < 0)
		num = -num;
	result = (char *)malloc((digits + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	result[digits--] = '\0';
	while (num > 0)
	{
		result[digits--] = num % 10 + '0';
		num = num / 10;
	}
	if (n < 0)
		result[0] = '-';
	return (result);
}