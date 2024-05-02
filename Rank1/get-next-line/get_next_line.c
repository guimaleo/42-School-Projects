/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lede-gui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:57:00 by lede-gui          #+#    #+#             */
/*   Updated: 2023/11/16 19:03:20 by lede-gui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	temp[BUFFER_SIZE + 1];
	char		*line;
	int			nl;

	nl = 0;
	line = 0;
	if (fd < 0 || fd > FOPEN_MAX 
		|| BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
	{
		while (nl < BUFFER_SIZE)
			temp[nl++] = 0;
		return (NULL);
	}
	nl = 0;
	while (*temp || (read(fd, temp, BUFFER_SIZE) > 0))
	{
		line = ft_joinbuff(line, temp, &nl);
		buff_flusher(temp);
		if (nl)
			break ;
	}
	return (line);
}
/*
int     main(int argc, char **argv)
{
    int     fd;
    char    *line;
    int     i;

    i = 1;
    if (argc == 2)
    {
        fd = open(argv[1], O_RDONLY);
        while (line = (get_next_line(fd)))
        {
            printf("line %i: %s", i, line);
            i++;
            free(line);
        }
        free(line);
        close(fd);
    }
    return (0);
}*/
