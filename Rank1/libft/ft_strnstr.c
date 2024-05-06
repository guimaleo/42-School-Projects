/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lede-gui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 16:16:31 by lede-gui          #+#    #+#             */
/*   Updated: 2023/10/16 13:14:08 by lede-gui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	little_len;

	little_len = ft_strlen(little);
	if (len < little_len)
		return (0);
	if (little_len == 0)
		return ((char *)big);
	while (*big && len >= little_len)
	{
		if ((*big == *little) && !ft_strncmp(big, little, little_len))
			return ((char *)big);
		big++;
		len--;
	}
	return (NULL);
}
/*
int	main()
{
	printf("Custom:   %s\n", ft_strnstr("BLABcLABLA","c", 10));
	printf("Original: %s\n", strnstr("BLABcLABLA", "c", 10));
}*/
