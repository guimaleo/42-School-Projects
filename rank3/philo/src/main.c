/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lede-gui <lede-gui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 21:59:30 by lede-gui          #+#    #+#             */
/*   Updated: 2025/02/16 20:12:36 by lede-gui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*philos(void)
{
	static t_philo	init;

	return (&init);
}

bool	validation(char **av)
{
	int		i[2];
	
	i[0] = 1;
	while (av[i[0]])
	{
		i[1] = 0;
		while (av[i[0]][i[1]])
		{
			if (!ft_isdigit(av[i[0]][i[1]]) && av[i[0]][i[1]] != '+' \
				&& av[i[0]][i[1]] != '-')
					return (true);
			i[1]++;
		}
		i[0]++;
	}
	return (false);
}

t_args	*vars(char **av)
{
	static t_args	init;
	
	init.nb = ft_uatoi(av[1]);
	init.die = ft_uatoi(av[2]);
	init.eat = ft_uatoi(av[3]);
	init.sleep = ft_uatoi(av[4]);
	if (av[5])
		init.meals = ft_uatoi(av[5]);
	else
		init.meals = 0;
	if (init.nb < 1 || init.die < 1 || init.eat < 1 
		|| init.sleep < 1 || init.meals < 0)
		return (NULL);
	else
	{
		philos()->nb = init.nb;
		philos()->die = init.die;
		philos()->eat = init.eat;
		philos()->sleep = init.sleep;
		philos()->meals = init.meals;
	}
	return (&init);
}

bool	ft_error(char *msg, void *ptr)
{
	if (ptr)
		free(ptr);
	write(2, msg, ft_strlen(msg));
	return (true);
}

int	main(int ac, char **av)
{
	bool    block;

	block = false;
	if (ac < 5 || ac > 6)
	{
		block = ft_error(USE, NULL);
		if (block)
			return (1);
	}
	else
	{
		block = validation(av);
		if (block)
			return (ft_error(DIG, NULL), 2);
		if (ft_uatoi(av[1]) > 200)
			return(ft_error(PHI_ERR, NULL), 3);
		philos()->var = vars(av);
		if (!philos()->var)
			return (ft_error(NEG, NULL), 3);
		if (!welcome_drink())
			return (ft_error(CREAT, NULL), 4);
		printf("All philos joined the table\n\ttotal threads: %i\n", philos()->nb);
	}
}
