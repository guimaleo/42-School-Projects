/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lede-gui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 20:27:36 by lede-gui          #+#    #+#             */
/*   Updated: 2023/10/15 14:58:31 by lede-gui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (fd < 0)
		return ;
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}
/*
int	main()
{
	int	fd;

	fd = open("./txt/testputnb.txt", O_APPEND | O_WRONLY, 0642);
	ft_putendl_fd("\n", fd);
	ft_putstr_fd("Nova linha?", fd);
	
}*/
