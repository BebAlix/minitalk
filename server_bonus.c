/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 19:24:32 by equesnel          #+#    #+#             */
/*   Updated: 2022/06/07 19:24:39 by equesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	g_c[2];

char	*get_malloc(char *str)
{
	str = malloc(sizeof(char) * (g_c[0] + 1));
	if (!str)
		return (NULL);
	return (str);
}

void	get_str(void)
{
	static int		i;
	static char		*str;
	static int		pid;

	if (!str)
	{
		str = get_malloc(str);
		return ;
	}
	if (pid == 0)
	{
		pid = g_c[0];
		return ;
	}
	str[i++] = g_c[0];
	if (g_c[0] == 0)
	{
		ft_printf("%s", str);
		kill(pid, SIGUSR1);
		free(str);
		str = NULL;
		i = 0;
		pid = 0;
	}
}

void	get_char(int signum, siginfo_t *pid, void *unused)
{
	(void) unused;
	(void) pid;
	if (signum == SIGUSR1)
		g_c[0] |= 1;
	if (++g_c[1] != 32)
		g_c[0] <<= 1;
}

int	main(void)
{
	struct sigaction	s_sa;

	ft_printf("PID : %d\n", getpid());
	s_sa.sa_flags = SA_SIGINFO;
	s_sa.sa_sigaction = get_char;
	sigaction(SIGUSR1, &s_sa, NULL);
	sigaction(SIGUSR2, &s_sa, NULL);
	g_c[1] = 0;
	g_c[0] = 0;
	while (1)
	{
		while (g_c[1] < 32)
			continue ;
		g_c[1] = 0;
		get_str();
		g_c[0] = 0;
	}
	return (0);
}
