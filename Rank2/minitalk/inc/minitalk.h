/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lede-gui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 13:58:50 by lede-gui          #+#    #+#             */
/*   Updated: 2024/10/06 13:58:54 by lede-gui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdio.h>
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>
# include <stddef.h>
# include <sys/types.h>
# include "./ft_printf/includes/libftprintf.h"

# define PID_ERR "Not a valid pid!\n"
# define ARG_ERR "Wrong arguments!\n\
Usage:\t./client <server pid> <message to be sent>\n"
# define SRV_ERR "Server failure\nExiting..."
# define STR_ERR "Non valid message\n"
# define SA_ERR "sa struct error!\n"
# define SVR_RCV "Message delivered to the server!\n"

int		ft_atoi(char *s);
bool	ft_pid_validation(char *av_pid);
void	ft_error(int flag);

#endif
