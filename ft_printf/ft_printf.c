/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 14:29:48 by equesnel          #+#    #+#             */
/*   Updated: 2022/04/16 14:29:51 by equesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_write(char type, va_list ap)
{
	int	len;

	if (type == 'c')
		len = ft_putchar_rl(va_arg(ap, int));
	if (type == 's')
		len = ft_putstr_rl(va_arg(ap, char *));
	if (type == 'p')
		len = ft_putadr_rl(va_arg(ap, unsigned long long));
	if (type == 'd' || type == 'i')
		len = ft_putnbr_base_rl("0123456789", va_arg(ap, int));
	if (type == 'u')
		len = ft_putnbr_base_rlu("0123456789", va_arg(ap, unsigned int));
	if (type == 'x')
		len = ft_putnbr_base_rlu("0123456789abcdef", va_arg(ap, unsigned int));
	if (type == 'X')
		len = ft_putnbr_base_rlu("0123456789ABCDEF", va_arg(ap, unsigned int));
	if (type == '%')
		len = ft_putchar_rl('%');
	return (len);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		len;
	va_list	ap;

	i = 0;
	len = 0;
	va_start(ap, s);
	while (s[i])
	{
		while (s[i] != '%' && s[i])
		{
			len += ft_putchar_rl(s[i]);
			i++;
		}
		if (s[i] == '%')
			i++;
		if (s[i])
		{
			len += ft_write(s[i], ap);
			i++;
		}
	}
	va_end(ap);
	return (len);
}
