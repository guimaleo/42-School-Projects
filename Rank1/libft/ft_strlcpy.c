/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lede-gui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 16:57:39 by lede-gui          #+#    #+#             */
/*   Updated: 2023/10/07 20:34:48 by lede-gui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(src);
	if (size != 0)
	{
		while (i < size -1 && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = 0;
	}
	return (len);
}
/*
int	main(void)
{
	char	*str;
	str = strdup("abc");
	printf("Original: %zu\n", strlcpy(str,"123", 4));
	printf("Custom:   %zu\n", ft_strlcpy(str,"123", 4));
}*/
