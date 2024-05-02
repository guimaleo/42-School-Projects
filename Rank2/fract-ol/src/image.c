/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lede-gui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 19:41:36 by lede-gui          #+#    #+#             */
/*   Updated: 2024/04/30 19:41:38 by lede-gui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	ft_fractal_choice(t_fractol *frac, t_complex c)
{
	int	i;

	i = 0;
	if (!ft_strcmp(frac->name, "Mandelbrot"))
		i = ft_mandelbrot(c, frac);
	else if (!ft_strcmp(frac->name, "Julia"))
	{
		if (frac->iter < 30)
			frac->iter = 30;
		i = ft_julia(c, frac);
	}
	else if (!ft_strcmp(frac->name, "Phoenix"))
		i = ft_phoenix(c, frac);
	return (i);
}

int	ft_color_choose(int i, t_fractol *canvas)
{
	int	color;
	int	r;
	int	g;
	int	b;

	color = 0;
	r = (int)((canvas->r) * (255 * ((1 - (i * KC)))));
	g = (int)((canvas->g) * (255 * ((1 - (i * KC)))));
	b = (int)((canvas->b) * (255 * ((1 - (i * KC)))));
	color = r << 16 | g << 8 | b;
	return (color);
}

void	ft_pixel_put(t_fractol *canvas, int x, int y, int color)
{
	char	*pixel;

	pixel = canvas->addr + (y * canvas->line_len + x * (canvas->bpp / 8));
	if (color < 0)
		color = (int)fabs(color * 0.1);
	*(unsigned int *)pixel = color;
}

void	ft_image(t_fractol *mlx, int control)
{
	if (control)
	{
		mlx->img = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
		mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bpp, \
		&mlx->line_len, &mlx->endian);
	}
	ft_render(mlx, 0);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
}
