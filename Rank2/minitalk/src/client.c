/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lede-gui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 13:57:51 by lede-gui          #+#    #+#             */
/*   Updated: 2024/10/06 13:57:54 by lede-gui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

bool	ft_pid_validation(char *av_pid)
{
	int		pid;

	if (ft_strlen(av_pid) > 8)
		return (false);
	pid = ft_atoi(av_pid);
	return (pid > 1 && !kill(pid, 0));
}

void	ft_send_str_len(char *msg, pid_t srv)
{
	size_t	len;
	int		bits;

	if (!msg)
		ft_error(4);
	len = ft_strlen(msg);
	bits = 31;
	while (bits >= 0)
	{
		if ((len >> bits) & 1)
			kill(srv, SIGUSR1);
		else
			kill(srv, SIGUSR2);
		bits--;
		usleep(200);
	}
}

static void	ft_sighandler(int sig)
{
	if (sig == SIGUSR1)
		ft_printf(SVR_RCV);
	exit(EXIT_SUCCESS);
}

void	ft_send_signal(char *msg, pid_t srv)
{
	int		i;
	int		j;

	i = 0;
	while (msg[i])
	{
		j = 7;
		while (j >= 0)
		{
			if ((msg[i] >> j) & 1)
				kill(srv, SIGUSR1);
			else
				kill(srv, SIGUSR2);
			j--;
			usleep(200);
		}
		i++;
	}
	i = 7;
	while (i >= 0)
	{
		kill(srv, SIGUSR2);
		i--;
		usleep(200);
	}
}

int	main(int ac, char **av)
{
	pid_t				srv;
	struct sigaction	sa;

	if (ac != 3)
		ft_error(2);
	sa.sa_handler = ft_sighandler;
	sa.sa_flags = 0;
	if (sigaction(SIGUSR1, &sa, NULL) || sigaction(SIGUSR2, &sa, NULL))
		ft_error(3);
	if (!ft_pid_validation(av[1]))
		ft_error(1);
	srv = ft_atoi(av[1]);
	ft_send_str_len(av[2], srv);
	ft_send_signal(av[2], srv);
	return (0);
}
