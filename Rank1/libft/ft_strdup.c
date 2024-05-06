/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lede-gui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 23:41:43 by lede-gui          #+#    #+#             */
/*   Updated: 2023/10/13 17:43:44 by lede-gui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*str;

	len = ft_strlen(s);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_memcpy(str, s, len);
	str[len] = 0;
	return (str);
}
/*
int	main(void)
{
	char	s1[] = "Borracha";
	char	*s3 = NULL;

	printf("%s\n", ft_strdup(s1));
	printf("%s\n", strdup(s3));
}*/
