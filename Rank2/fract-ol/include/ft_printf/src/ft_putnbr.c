/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lede-gui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 12:53:12 by lede-gui          #+#    #+#             */
/*   Updated: 2023/10/16 19:46:58 by lede-gui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putnbr(int n)
{
	int	chars;

	chars = 0;
	if (n < 0)
	{
		if (n == -2147483648)
		{
			ft_putstr("-2147483648");
			return (ft_strlen("-2147483648"));
		}
		ft_putchar('-');
		n *= -1;
	}
	if (n < 10)
	{
		chars += ft_putchar(n + 48);
		return (chars);
	}
	else
	{
		chars += ft_putnbr(n / 10);
		chars += ft_putnbr(n % 10);
		return (chars);
	}
}
