#include "ft_printf.h"

int	int_ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	int_ft_putstr(char *s)
{
	int	ret;

	ret = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (*s)
	{
		write(1, s, 1);
		s++;
		ret++;
	}
	return (ret);
}

int	int_ft_putposhex(unsigned long long int num, int shift)
{
	char						hex[17];
	char						c;
	unsigned long long int		rem;
	int							j;
	int							i;

	j = 0;
	i = -1;
	while (num)
	{
		rem = num % 16;
		if (rem < 10)
			hex[j++] = 48 + rem;
		else
			hex[j++] = shift + rem;
		num /= 16;
	}
	--j;
	while (++i <= j / 2)
	{
		c = hex[i];
		hex[i] = hex[j - i];
		hex[j - i] = c;
	}
	hex[++j] = '\0';
	return (int_ft_putstr(hex));
}

int	int_ft_putneghex(long long int num, int shift)
{
	if (num < 0)
		num = 4294967296 + num;
	if (!num)
		return (int_ft_putstr("0"));
	return (int_ft_putposhex(num, shift));
}

int	int_ft_putptr(unsigned long long int p)
{
	if (!p)
		return (int_ft_putstr("(nil)"));
	return (int_ft_putstr("0x") + int_ft_putposhex(p, 87));
}