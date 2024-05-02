/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lede-gui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 21:20:52 by lede-gui          #+#    #+#             */
/*   Updated: 2023/10/16 14:02:16 by lede-gui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*ptr;

	ptr = (char *)s;
	i = 0;
	while (ptr[i])
	{
		if (ptr[i] == (char)c)
			return (ptr + i);
		i++;
	}
	if (ptr[i] == (char)c)
		return (ptr + i);
	return (0);
}

/*
int	main()
{
	char	str[] = "BATATA CORTADA!";
	printf("%s\n", ft_strchr(str, 32));
	printf("%s\n", strchr(str, 32));
	printf("%s\n", ft_strchr(str, 0));
	printf("%s\n", strchr(str, 0));
}*/
