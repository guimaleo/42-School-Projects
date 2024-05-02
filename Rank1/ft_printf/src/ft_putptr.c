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

void	ft_putptr(void *address)
{
	if (!address)
	{
		ft_putstr("(nil)");
		return ;
	}
	else
	{
		ft_putstr("0x");
		ft_convert_any_base((unsigned long)address, HEX_LOW);
	}
}
