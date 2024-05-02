/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lede-gui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:04:07 by lede-gui          #+#    #+#             */
/*   Updated: 2023/11/16 19:11:42 by lede-gui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
		return (NULL);
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
// int     main()
// {
//     char    str[] = "1234567890abcdefghij";
//     char    s2[] = "ABCDEFGHIJ0987654321";
//     int     flag = 0;

//     printf("length until \\n or full: %i\n", hit_nl(str, &flag));
//     printf("flag value: %i\n", flag);
//     printf("joinbuff return: %s\n", ft_joinbuff(str, s2, &flag));
// }
