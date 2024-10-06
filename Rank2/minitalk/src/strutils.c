/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strutils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lede-gui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 13:58:06 by lede-gui          #+#    #+#             */
/*   Updated: 2024/10/06 13:58:24 by lede-gui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

void	ft_error(int flag)
{
	if (flag == 1)
		ft_printf(PID_ERR);
	if (flag == 2)
		ft_printf(ARG_ERR);
	if (flag == 3)
		ft_printf(SRV_ERR);
	if (flag == 4)
		ft_printf(STR_ERR);
	if (flag == 5)
		ft_printf(SA_ERR);
	exit(EXIT_FAILURE);
}

int	ft_atoi(char *s)
{
	int		sign;
	int		res;

	sign = 1;
	res = 0;
	while (*s == 32 || (*s > 8 && *s < 14))
		s++;
	if (*s == 43 || *s == 45)
	{
		if (*s == 45)
			sign = -1;
		s++;
	}
	while (*s > 47 && *s < 58)
	{
		if (sign > 0)
			res = res * 10 + (*s++ - 48);
		else
			res = res * 10 - (*s++ - 48);
	}
	return (res);
}
