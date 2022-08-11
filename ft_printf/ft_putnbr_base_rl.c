/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_rl.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 21:20:25 by equesnel          #+#    #+#             */
/*   Updated: 2022/04/19 21:20:29 by equesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_base_rl(char *base, long int nb)
{
	int		len;
	int		len_base;

	len_base = ft_strlen(base);
	len = 0;
	if (nb < 0)
	{
		nb = -nb;
		len += ft_putchar_rl('-');
	}
	if (nb >= len_base)
	{
		len += ft_putnbr_base_rl(base, (nb / len_base));
		len += ft_putchar_rl(base[nb % len_base]);
	}
	else
		len += ft_putchar_rl(base[nb]);
	return (len);
}
