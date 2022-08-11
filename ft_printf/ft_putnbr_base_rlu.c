/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_rlu.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 21:20:47 by equesnel          #+#    #+#             */
/*   Updated: 2022/04/19 21:20:53 by equesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_putnbr_base_rlu(char *base, unsigned long long nb)
{
	unsigned long long		len;
	unsigned long long		len_base;

	len_base = ft_strlen(base);
	len = 0;
	if (nb >= len_base)
	{
		len += ft_putnbr_base_rl(base, (nb / len_base));
		len += ft_putchar_rl(base[nb % len_base]);
	}
	else
		len += ft_putchar_rl(base[nb]);
	return (len);
}
