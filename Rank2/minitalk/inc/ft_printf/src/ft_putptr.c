/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lede-gui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 13:18:07 by lede-gui          #+#    #+#             */
/*   Updated: 2023/10/16 19:11:24 by lede-gui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putptr(void *address)
{
	int	res;

	res = 0;
	if (!address)
	{
		ft_putstr("(nil)");
		return (0);
	}
	else
	{
		ft_putstr("0x");
		res += ft_convert_any_base((unsigned long)address, HEX_LOW);
	}
	return (res);
}
