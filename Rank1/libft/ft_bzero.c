/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lede-gui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:04:15 by lede-gui          #+#    #+#             */
/*   Updated: 2023/10/05 22:31:15 by lede-gui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
/*
#include <string.h>
int	main()
{
	void	*ptr;
	void	*ptr2;
	int	i;

	i = 0;
	ptr = malloc(10);
	ptr2 = malloc(10);
	if (!ptr || !ptr2)
	{
		printf("malloc error!\n");
		return (1);
	}
	while (i < 10)
	{
		((char *)ptr)[i] = 65;
		i++;
	}
	i = 0;
	printf("Before ft_bzero: %s\n", (char *)ptr);
	ft_bzero(ptr, 5);
	bzero(ptr2, 5);
	printf("After bzero: %s\nRemember null is non printable!!!\n", (char *)ptr);
}*/
