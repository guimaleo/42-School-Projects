/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lede-gui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 23:34:52 by lede-gui          #+#    #+#             */
/*   Updated: 2023/10/12 23:42:08 by lede-gui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*dest;
	unsigned char	*byte_dest;

	dest = malloc(nmemb * size);
	if (!dest)
		return (NULL);
	byte_dest = (unsigned char *)dest;
	ft_bzero(byte_dest, (nmemb * size));
	return (dest);
}
