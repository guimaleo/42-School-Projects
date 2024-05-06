/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lede-gui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 16:41:36 by lede-gui          #+#    #+#             */
/*   Updated: 2023/10/07 16:56:39 by lede-gui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	int		i;

	ptr = (char *)s;
	i = ft_strlen(s);
	if (c == 0)
		return (ptr + i);
	while (i >= 0)
	{
		if (ptr[i] == (char)c)
			return (ptr + i);
		i--;
	}
	return (NULL);
}
/*
int	main(void)
{
	printf("Custom:   %s|\n", ft_strrchr("fah sfh", 32));
	printf("Original: %s|\n", strrchr("fah sfh", 32));
}*/
