#include "ft_printf.h"

static int	conversions(char c, va_list ap)
{
	if (c == 'c')
		return (int_ft_putchar((char)va_arg(ap, int)));
	if (c == 's')
		return (int_ft_putstr(va_arg(ap, char *)));
	if (c == 'p')
		return (int_ft_putptr(va_arg(ap, unsigned long)));
	if (c == 'd' || c == 'i')
		return(int_ft_putnbr(va_arg(ap, int)));
	if (c == 'u')
		return(int_ft_putunsnbr(va_arg(ap, unsigned int)));
	if (c == 'X')
		return(int_ft_putneghex((long long int)va_arg(ap, int), 55));
	if (c == 'x')
		return(int_ft_putneghex((long long int)va_arg(ap, int), 87));
	if (c == '%')
		return (int_ft_putchar('%'));
	return (0);
}

int ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		len;

	va_start(ap, format);
	i = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			len += conversions(format[i + 1], ap);
			i += 2;
		}
		else
			len += int_ft_putchar(format[i++]);
	}
	va_end(ap);
	return (len);
}

// int main(void)
// {
// 	const char	*out = "%u\n";
// 	//long int	b = 0;
// 	//unsigned long int b = ULONG_MAX;
// 	//char	*s = NULL;
// 	if (ft_printf(out, -1) == printf(out, -1))
// 		ft_printf("\nyolo\n");
// 	// printf("Columns:\n" );
// 	// printf("%d\n\n", printf("0123456789012345678901234567890123456789\n" );
// 	// printf("%10s%10d%10c%10f\n\n", "hello", 7, 'a', 3.1415);
// 	// printf("%-10s%-10d%-10c%-10f\n", "hello", 7, 'a', 3.1415);
// }