/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lede-gui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 19:41:46 by lede-gui          #+#    #+#             */
/*   Updated: 2024/04/30 19:41:47 by lede-gui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	*ft_instructions(t_fractol *comm)
{
	void	*win;
	int		kill;

	win = mlx_new_window(comm->mlx, 200, 180, "Instructions");
	kill = mlx_hook(win, 17, 0L, ft_destroy_inst, comm);
	if (kill)
		free(win);
	return (win);
}
static char	**ft_inst_win(void)
{
	char	**ret;

	ret = (char **)malloc(9 * sizeof(char *));
	if (!ret)
		return (ret);
	ret[0] = "R -> Increase red factor";
	ret[1] = "G -> Increase green factor";
	ret[2] = "B -> Increase blue factor";
	ret[3] = " + or mouse wheel -> Zoom in";
	ret[4] = " - or mouse wheel -> Zoom out";
	ret[5] = "I -> Increase iterations";
	ret[6] = "W A S D -> Movement";
	ret[7] = "Arrow keys -> Movement";
	ret[8] = 0;
	return (ret);
}

void	ft_text_inst(t_fractol *comm)
{
	int	i;
	int	line;
	int	column;
	char	**txt;
	void	*win;

	win = ft_instructions(comm);
	i = 0;
	line = 10;
	column = 0;
	txt = ft_inst_win();
	while (i < 8)
	{
		column += 20;
		mlx_string_put(comm->mlx, win, line, \
		column, 0x00FF00, txt[i]);
		i++;
	}
}
