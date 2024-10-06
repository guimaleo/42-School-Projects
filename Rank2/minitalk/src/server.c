/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lede-gui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 13:57:58 by lede-gui          #+#    #+#             */
/*   Updated: 2024/10/06 13:58:00 by lede-gui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

static int		g_bits;

void	flush_bits(char *str, int *len, int *j, int pid)
{
	ft_printf("%s", str);
	free(str);
	*len = 0;
	*j = 0;
	g_bits = 0;
	kill(pid, SIGUSR1);
}

void	ft_stralloc(char **str, int len)
{
	*str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		exit(EXIT_FAILURE);
	(*str)[len] = 0;
}

void	ft_sigusr1(int sig, siginfo_t *info, void *context)
{
	static char		*str;
	static char		c;
	static int		i;
	static int		j;
	static int		len;

	(void)context;
	if (g_bits++ < 32)
		len = (len << 1) + (sig >> 1 & 1);
	else
	{
		if (g_bits == 33)
			ft_stralloc(&str, len);
		c = (c << 1) + (sig >> 1 & 1);
		i++;
		if (i == 8)
		{
			str[j++] = c;
			if (c == '\0')
				flush_bits(str, &len, &j, info->si_pid);
			c = 0;
			i = 0;
		}
	}
}

int	main(void)
{
	pid_t				srv_id;
	struct sigaction	sa;

	sa.sa_sigaction = ft_sigusr1;
	sa.sa_flags = SA_SIGINFO;
	if (sigemptyset(&sa.sa_mask) == -1)
		ft_error(4);
	srv_id = getpid();
	if (sigaction(SIGUSR1, &sa, NULL) || sigaction(SIGUSR2, &sa, NULL))
		ft_error(3);
	ft_printf("Server process id: %i\nNeeded to run on client side.\n", srv_id);
	while (1)
		pause();
	return (0);
}
