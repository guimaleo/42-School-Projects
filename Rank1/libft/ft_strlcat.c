/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lede-gui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 17:39:42 by lede-gui          #+#    #+#             */
/*   Updated: 2023/10/15 14:24:52 by lede-gui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len;
	size_t	i;

	len = 0;
	while (dst[len] && len < size)
		len++;
	i = 0;
	while (src[i] && (len + i + 1) < size)
	{
		dst[len + i] = src[i];
		i++;
	}
	if ((len + i) < size)
		dst[len + i] = 0;
	i = ft_strlen(src);
	return (len + i);
}
/*
int	main(void)
{
	char	*str;
	char	*str2;

	str = strdup("Potato");
	str2 = "Pomme de terre";
//	printf("%zu\n", ft_strlcat(str, str2, 12));
	printf("%s\n", str);
	printf("%zu\n", strlcat(str, str2, 12));
	printf("%s\n", str);
}*/
