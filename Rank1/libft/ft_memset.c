/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lede-gui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 20:28:09 by lede-gui          #+#    #+#             */
/*   Updated: 2023/10/05 22:29:47 by lede-gui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
/*
int	main()
{
	void	*ptr;
	void	*ptr2;

	ptr = malloc(10);
	ptr2 = malloc(10);
	if (!ptr || !ptr2)
		return (1);
	ptr = memset(ptr, 65, 8);
	printf("%s|\n", (char *)ptr);
	ptr2 = ft_memset(ptr2, 53, 6);
	printf("%s|\n", (char *)ptr2);
	free(ptr);
	free(ptr2);
}*/
