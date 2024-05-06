/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lede-gui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 21:36:10 by lede-gui          #+#    #+#             */
/*   Updated: 2023/10/06 21:51:11 by lede-gui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	sign;
	int	result;

	if (!nptr)
		return (-1);
	sign = 1;
	result = 0;
	while (*nptr == 32 || (*nptr > 8 && *nptr < 14))
		nptr++;
	if (*nptr == 43 || *nptr == 45)
	{
		if (*nptr == 45)
			sign *= -1;
		nptr++;
	}
	while (*nptr > 47 && *nptr < 58)
	{
		if (sign == 1)
			result = (result * 10) + (*nptr - 48);
		else
			result = (result * 10) - (*nptr - 48);
		nptr++;
	}
	return (result);
}
/*
int	main(int ac, char **av)
{
	int	i;
	if (ac > 2)
		return (1);
	i = 1;
	while (i < ac)
	{
		printf("%i\n", ft_atoi(av[i]));
		i++;
	}

}*/
