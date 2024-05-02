/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lede-gui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 12:50:11 by lede-gui          #+#    #+#             */
/*   Updated: 2023/10/16 19:52:07 by lede-gui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putstr(const char *str)
{
	int	chars;

	chars = 0;
	while (*str)
	{
		chars += write(1, str, 1);
		str++;
	}
	return (chars);
}
