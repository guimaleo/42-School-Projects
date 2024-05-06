/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lede-gui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 20:35:06 by lede-gui          #+#    #+#             */
/*   Updated: 2023/10/16 14:01:50 by lede-gui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcat(char *s, char *s2)
{
	int	len;
	int	i;

	i = 0;
	len = ft_strlen(s);
	while (s2[i])
	{
		s[len + i] = s2[i];
		i++;
	}
	s[len + i] = 0;
	return (s);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*ptr;
	size_t	len;
	char	*ptr_s1;
	char	*ptr_s2;

	ptr_s1 = (char *)s1;
	ptr_s2 = (char *)s2;
	if (!s1 || !s2)
		return (NULL);
	len = (ft_strlen(s1) + ft_strlen(s2));
	ptr = (char *)malloc((len + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	ptr[0] = 0;
	ft_strcat(ptr, ptr_s1);
	ft_strcat(ptr, ptr_s2);
	ptr[ft_strlen(ptr) + 1] = 0;
	return (ptr);
}
/*
int	main(void)
{
	char	str[] = "Philosophers";
	char	str2[] = "Stoneds";

	printf("%s\n", ft_strjoin(str, str2));
}*/
