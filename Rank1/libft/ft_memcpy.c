/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lede-gui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 17:03:28 by lede-gui          #+#    #+#             */
/*   Updated: 2023/10/06 21:54:41 by lede-gui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*ptr_dest;
	const char	*ptr_src;

	if (!dest && !src)
		return (0);
	ptr_dest = (char *)dest;
	ptr_src = (const char *)src;
	i = 0;
	while (i < n)
	{
		ptr_dest[i] = ptr_src[i];
		i++;
	}
	return (dest);
}
/*
int	main()
{
	char	tab[] = "CHULA PATCHULA";
	char	str[] = "Memory";
	
	printf("Before function tab: %p\n%s\n", &tab, tab);
	printf("Before function str: %p\n%s\n", &str, str);
	ft_memcpy(tab, str, 6);
	printf("After function tab: \n\033[1;32mAddress:\033[0m\n
	%p\n\n\033[1;36mContent:\033[0m%s\n", &tab, tab);
	printf("After function str: \n\033[1;32mAddress:\033[0m\n
	%p\n\n\033[1;36mContent:\033[0m%s\n", &str, str);
}*/
