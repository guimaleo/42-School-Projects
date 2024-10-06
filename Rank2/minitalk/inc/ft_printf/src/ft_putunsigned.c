/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lede-gui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 13:25:50 by lede-gui          #+#    #+#             */
/*   Updated: 2023/10/16 19:52:38 by lede-gui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putunsigned(unsigned int u)
{
	int	chars;

	chars = 0;
	if (u < 10)
		chars += ft_putchar(u + 48);
	else
	{
		chars += ft_putunsigned(u / 10);
		chars += ft_putunsigned(u % 10);
	}
	return (chars);
}
