/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lede-gui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:12:07 by lede-gui          #+#    #+#             */
/*   Updated: 2023/11/16 19:16:42 by lede-gui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	hit_nl(char *str, int **flag)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == 10)
		{
			**flag = 1;
			return (i + 1);
		}
		i++;
	}
	return (i);
}

char	*ft_joinbuff(char *dst, char *buff, int *flag)
{
	char	*ret;
	int		i;
	int		j;
	int		**to_flag;

	to_flag = &flag;
	i = 0;
	j = 0;
	ret = malloc(hit_nl(dst, to_flag) + hit_nl(buff, to_flag) + 1);
	if (!ret)
		return (0);
	while (dst && dst[i])
	{
		ret[i] = dst[i];
		i++;
	}
	while (buff && (j < (hit_nl(buff, to_flag))))
		ret[i++] = buff[j++];
	ret[i] = 0;
	if (dst)
		free(dst);
	return (ret);
}

void	buff_flusher(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == 10)
		{
			i++;
			break ;
		}
		else if (str[i + 1] == 10)
		{
			i += 2;
			break ;
		}
		i++;
	}
	while (str[i])
		str[j++] = str[i++];
	while (str[j])
		str[j++] = 0;
}
