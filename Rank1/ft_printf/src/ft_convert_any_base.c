/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_any_base.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lede-gui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 13:12:23 by lede-gui          #+#    #+#             */
/*   Updated: 2023/10/16 19:45:24 by lede-gui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static unsigned long	ft_strlen(const char *str)
{
	unsigned long	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	ft_convert_any_base(unsigned long l, char *base)
{
	unsigned long	len;
	int	chars;

	len = ft_strlen(base);
	if ((l / len) == 0)
		chars += ft_putchar(base[l % len]);
	else
	{
		ft_convert_any_base((l / len), base);
		ft_convert_any_base((l % len), base);
	}
}
