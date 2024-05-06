/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lede-gui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 20:04:16 by lede-gui          #+#    #+#             */
/*   Updated: 2023/10/16 13:22:25 by lede-gui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (fd < 0 || !s)
		return ;
	while (*s)
		write(fd, s++, 1);
}
/*
int	main()
{
	int	fd;

	fd = open("./txt/teststr.txt", O_CREAT | O_WRONLY, 0666);
	ft_putstr_fd("Escreva a informacao aqui!\n", fd);
	close(fd);
}*/
