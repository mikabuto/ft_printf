/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikabuto <mikabuto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 14:35:37 by mikabuto          #+#    #+#             */
/*   Updated: 2021/12/04 14:35:37 by mikabuto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	ft_swap(char *a, char *b)
{
	char	c;

	c = *a;
	*a = *b;
	*b = c;
}

int	int_ft_putposhex(unsigned long long int num, int shift)
{
	char						hex[17];
	unsigned long long int		rem;
	int							j;
	int							i;

	j = 0;
	i = -1;
	if (!num)
		return (int_ft_putstr("0"));
	while (num)
	{
		rem = num % 16;
		if (rem < 10)
			hex[j++] = 48 + rem;
		else
			hex[j++] = shift + rem;
		num /= 16;
	}
	while (++i <= (j - 1) / 2)
		ft_swap(&(hex[i]), &(hex[(j - 1) - i]));
	hex[j] = '\0';
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
