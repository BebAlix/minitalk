/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 11:22:05 by equesnel          #+#    #+#             */
/*   Updated: 2022/04/15 11:24:01 by equesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int			ft_putchar_rl(char c);
int			ft_putstr_rl(char *str);
int			ft_putnbr_base_rl(char *base, long int nb);
long long	ft_putnbr_base_rlu(char *base, unsigned long long nb);
long long	ft_putadr_rl(unsigned long long adr);
size_t		ft_strlen(const char *s);
int			ft_printf(const char *s, ...);

#endif
