/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lede-gui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:55:47 by lede-gui          #+#    #+#             */
/*   Updated: 2023/11/16 18:56:42 by lede-gui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	temp[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*line;
	int			nl;

	nl = 0;
	line = NULL;
	if (fd < 0 || fd > FOPEN_MAX || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
	{
		while (fd >= 0 && fd < FOPEN_MAX && temp[fd][nl])
			temp[fd][nl++] = 0;
		return (NULL);
	}
	nl = 0;
	while (*temp[fd] || read(fd, temp[fd], BUFFER_SIZE) > 0)
	{
		temp[fd][BUFFER_SIZE] = 0;
		line = ft_joinbuff(line, temp[fd], &nl);
		buff_flusher(temp[fd]);
		if (nl)
			break ;
	}
	return (line);
}
