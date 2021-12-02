#include "ft_printf.h"

static int	ft_num_len(long long int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static int	ft_power(int a)
{
	int	n;

	n = 1;
	while (a--)
		n *= 10;
	return (n);
}

int	int_ft_putnbr(int n)
{
	int		len;
	int		ret;
	int		i;

	i = 0;
	ret = 0;
	if (n == -2147483648)
		return (int_ft_putstr("-2147483648"));
	if (n < 0)
	{
		ret += int_ft_putchar('-');
		n = -n;
	}
	len = ft_num_len(n);
	ret += len;
	while (i < len)
	{
		i += int_ft_putchar((n / ft_power(len - i - 1) % 10) + '0');
	}
	return (ret);
}

int	int_ft_putunsnbr(long long int n)
{
	int		len;
	int		i;

	i = 0;
	len = ft_num_len(n);
	if (n < 0)
		n = 4294967296 + n;
	while (i < len)
	{
		i += int_ft_putchar((n / ft_power(len - i - 1) % 10) + '0');
	}
	return (len);
}
