/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lede-gui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:07:23 by lede-gui          #+#    #+#             */
/*   Updated: 2023/10/15 14:51:28 by lede-gui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*ptr_dest;
	unsigned char	*ptr_src;

	if (!src || !dest)
		return (0);
	ptr_dest = (unsigned char *)dest;
	ptr_src = (unsigned char *)src;
	if (dest < src)
		ft_memcpy(dest, src, n);
	else
	{
		while (n > 0)
		{
			--n;
			ptr_dest[n] = ptr_src[n];
		}
	}
	return (dest);
}
/*
int	main()
{
	char	tab[] = "1 4 6 9";
	char	str[] = "mem is confusing";

	printf("Address:\n%p\nContent\n%s\n", &tab, tab);
	printf("Address:\n%p\nContent\n%s\n", &str, str);
	ft_memmove(str, tab, 7);
	printf("Address:\n%p\nContent\n%s\n", &tab, tab);
	printf("Address:\n%p\nContent\n%s\n", &str, str);
}*/
