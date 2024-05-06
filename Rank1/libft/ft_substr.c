/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lede-gui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 19:19:52 by lede-gui          #+#    #+#             */
/*   Updated: 2023/10/16 13:18:47 by lede-gui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, size_t start, size_t len)
{
	char	*ptr;
	size_t	i;
	size_t	slen;

	slen = ft_strlen(s);
	if (start >= slen || len == 0)
		return (ft_calloc(1, sizeof(char)));
	else if (len > slen - start)
		len = slen - start;
	i = 0;
	ptr = (char *)malloc(len + 1);
	if (!ptr)
		return (NULL);
	while (s[start + i] && i < len)
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = 0;
	return (ptr);
}
