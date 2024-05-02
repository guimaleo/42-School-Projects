/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lede-gui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 19:52:21 by lede-gui          #+#    #+#             */
/*   Updated: 2023/10/15 14:25:49 by lede-gui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	if (fd < 0)
		return ;
	write(fd, &c, 1);
}
/*
int	main()
{
	int	fd;

	fd = open("./txt/test.txt", O_CREAT | O_WRONLY, 0742);
	ft_putchar_fd('T', fd);
	close(fd);
}*/
