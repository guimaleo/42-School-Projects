/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lede-gui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 19:41:04 by lede-gui          #+#    #+#             */
/*   Updated: 2024/04/30 20:04:55 by lede-gui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static t_complex	ft_init_complex(t_fractol *av)
{
	t_complex	c;

	(void)av;
	c.real = 0.0;
	c.imag = 0.0;
	return (c);
}

int	ft_mandelbrot(t_complex c, t_fractol *frac)
{
	t_complex	z;
	int			i;
	double		temp_real;

	z.real = 0.0;
	z.imag = 0.0;
	i = 0;
	while (i < frac->iter)
	{
		temp_real = z.real;
		z.real = (z.real * z.real) - (z.imag * z.imag) + c.real;
		z.imag = 2 * temp_real * z.imag + c.imag;
		if (z.real * z.real + z.imag * z.imag > 4)
			return (i);
		i++;
	}
	return (frac->iter);
}

int	ft_julia(t_complex z, t_fractol *frac)
{
	int			i;
	double		temp[2];

	i = 0;
	while (i < frac->iter)
	{
		temp[0] = z.real;
		temp[1] = z.imag;
		z.real = (temp[0] * temp[0]) - (temp[1] * temp[1]) + frac->av2;
		z.imag = 2 * temp[0] * temp[1] + (-1 * frac->av3);
		if (z.real * z.real + z.imag * z.imag > 4)
			return (i);
		i++;
	}
	return (frac->iter);
}

int	ft_phoenix(t_complex z, t_fractol *frac)
{
	int			i;
	double		tmp[2];

	i = 0;
	while (i < frac->iter)
	{
		tmp[0] = z.real;
		tmp[1] = z.imag;
		z.real = (tmp[0] * tmp[0]) - (tmp[1] * tmp[1]) + frac->av2 \
		+ (frac->av4 * tmp[0]);
		z.imag = 2 * tmp[0] * tmp[1] + (-1 * frac->av3) + (frac->av4 * tmp[1]);
		if ((z.real * z.real) + (z.imag * z.imag) > 4)
			return (i);
		i++;
	}
	return (frac->iter);
}

void	ft_render(t_fractol *canvas, int color)
{
	int			y;
	int			x;
	int			i;
	t_complex	c;

	c = ft_init_complex(canvas);
	y = 0;
	while (y++ < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			i = 0;
			c.real = ft_scale((double)x + canvas->x_coord, -2 / canvas->zoom,
					+ 2 / canvas->zoom, WIDTH);
			c.imag = ft_scale((double)y + canvas->y_coord, -2 / canvas->zoom,
					+ 2 / canvas->zoom, HEIGHT);
			i = ft_fractal_choice(canvas, c);
			if (i == canvas->iter)
				color = 0;
			else
				color = ft_color_choose(i, canvas);
			ft_pixel_put(canvas, x, y, color);
		}
	}
}
