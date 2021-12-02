#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>

#include <stdio.h> //TODO
#include <limits.h> //TODO

int ft_printf(const char *format, ...);
int	int_ft_putchar(char c);
int	int_ft_putstr(char *s);
int	int_ft_putnbr(int n);
int	int_ft_putunsnbr(long long int n);
int	int_ft_putposhex(unsigned long long int num, int shift);
int	int_ft_putneghex(long long int num, int shift);
int	int_ft_putptr(unsigned long long int p);

# endif