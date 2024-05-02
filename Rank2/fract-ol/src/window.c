/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lede-gui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 19:42:45 by lede-gui          #+#    #+#             */
/*   Updated: 2024/04/30 19:42:48 by lede-gui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

// int	ft_destroy_inst(t_fractol *inst)
// {
// 	if (inst)
// 	{
// 		mlx_destroy_window(inst->mlx, inst);
// 		inst->flag = 0;
// 	}
// 	return (0);
// }

int	ft_destroy(t_fractol *window)
{
	if (window)
	{
		mlx_destroy_image(window->mlx, window->img);
		mlx_destroy_window(window->mlx, window->win);
		// if (window->flag)
		// 	mlx_destroy_window(window->mlx, window);
		mlx_destroy_display(window->mlx);
		free(window->mlx);
		exit (EXIT_SUCCESS);
	}
	else
		return (-1);
	return (0);
}

t_fractol	ft_mlx_communication(int x, int y, t_fractol *comm)
{
	comm->mlx = mlx_init();
	if (!comm->mlx)
		return (*comm);
	comm->win = mlx_new_window(comm->mlx, x, y, "fract-ol");
	// comm = mlx_new_window(comm->mlx, 200, 180, "Instructions");
	if (!comm->mlx || !comm->win)
	{
		ft_error("Bad MLX");
		ft_destroy(comm);
		return (*comm);
	}
	// comm->flag = 1;
	return (*comm);
}
