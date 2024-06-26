/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lede-gui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 19:41:56 by lede-gui          #+#    #+#             */
/*   Updated: 2024/04/30 19:42:26 by lede-gui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

double	ft_scale(double to_scale, double new_min, \
double new_max, double old_max)
{
	return ((new_max - new_min) * (to_scale) / \
	(old_max) + new_min);
}

float	ft_atof(char *s)
{
	float	sign;
	float	res;

	sign = 1.0;
	res = 0.0;
	while (*s == 32 || (*s > 8 && *s < 14))
		s++;
	if (*s == 43 || *s == 45)
	{
		if (*s == 45)
			sign = -1;
		s++;
	}
	while (*s > 47 && *s < 58)
		res = res * 10 + (*s++ - 48);
	if (*s++ == '.')
	{
		while (*s)
		{
			sign *= 0.1;
			res = res * 10 + (*s++ - 48);
		}
	}
	return (res * sign);
}
