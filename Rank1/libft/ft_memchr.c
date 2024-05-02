/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lede-gui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:23:22 by lede-gui          #+#    #+#             */
/*   Updated: 2023/10/06 21:55:58 by lede-gui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (ptr[i] == (unsigned char)c)
			return (ptr + i);
		i++;
	}
	return (0);
}
/*
int	main()
{
	void	*res;
	char	str[] = "faugfailf gaijijia|OH DAMN YOU FOUND ME!
	aohfuiahguihuihajgkagjaljlfj;afj if a fit i sit hahuhoie";
	res = ft_memchr(str, 124, ft_strlen(str));
	if (res)
	{
		printf("%s\n", (char *)res);
	}
	return (0);
}*/
