/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 15:46:28 by equesnel          #+#    #+#             */
/*   Updated: 2022/05/11 15:46:29 by equesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	send_pid(int pid_server)
{
	int	byte;
	int	pid_client;

	pid_client = getpid();
	byte = 32;
	while (byte--)
	{
		if (pid_client >> byte & 1)
			kill(pid_server, SIGUSR1);
		else
			kill(pid_server, SIGUSR2);
		usleep(50);
	}
	return (0);
}

void	send_len(int pid, int len)
{
	int		byte;

	byte = 32;
	while (byte--)
	{
		if (len >> byte & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(50);
	}
	return ;
}

void	send_message(int pid, char *str)
{
	int		byte;
	int		len;

	len = ft_strlen(str);
	if (!len)
	{
		ft_printf("%s", "Empty String !");
		return ;
	}
	send_len(pid, len);
	len++;
	send_pid(pid);
	while (len--)
	{
		byte = 32;
		while (byte--)
		{
			if (*str >> byte & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(50);
		}
		str++;
	}
}

void	message_received(int signum, siginfo_t *pid, void *unused)
{
	(void) unused;
	(void) pid;
	if (signum == SIGUSR1)
		ft_printf("%s", "message_received !");
}

int	main(int ac, char **av)
{
	struct sigaction	s_sa;

	s_sa.sa_flags = SA_SIGINFO;
	s_sa.sa_sigaction = message_received;
	sigaction(SIGUSR1, &s_sa, NULL);
	if (ac == 3)
		send_message(ft_atoi(av[1]), av[2]);
	else
		ft_printf("%s", "Invalid number of arguments");
	usleep(2000);
	return (0);
}
