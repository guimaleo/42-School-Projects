/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lede-gui <lede-gui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 19:41:25 by lede-gui          #+#    #+#             */
/*   Updated: 2025/09/17 11:41:30 by lede-gui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	ft_zooming(int action, t_fractol *image, int x_0, int y_0)
{
	if (action == XK_equal || action == SCRU)
	{
		image->zoom = image->zoom * 1.1;
		image->x_coord = image->x_coord * 1.1 + x_0;
		image->y_coord = image->y_coord * 1.1 + y_0;
	}
	else if (action == XK_minus || action == SCRD)
	{
		image->zoom = image->zoom / 1.1;
		image->x_coord = image->x_coord / 1.1 + x_0;
		image->y_coord = image->y_coord / 1.1 + y_0;
	}
	ft_image(image, 0);
	return (0);
}

int	ft_moving(int key, t_fractol *img)
{
	if (key == XK_Up || key == XK_w)
		img->y_coord -= 5;
	else if (key == XK_Down || key == XK_s)
		img->y_coord += 5;
	else if (key == XK_Left || key == XK_a)
		img->x_coord -= 5;
	else if (key == XK_Right || key == XK_d)
		img->x_coord += 5;
	return (0);
}

int	ft_key_pressed(int key, t_fractol *sign)
{
	if (key == XK_Escape || !sign)
		ft_destroy(sign);
	else if (key == XK_r)
		sign->r += 1;
	else if (key == XK_g)
		sign->g += 1;
	else if (key == XK_b)
		sign->b += 1;
	else if (key == XK_equal || key == XK_minus)
		ft_zooming(key, sign, 0, 0);
	else if (key == XK_i)
		sign->iter += 1;
	else if (key == XK_k)
		sign->iter -= 1;
	else if (key == XK_2)
		sign->av2 += .001;
	else if (key == XK_3)
		sign->av3 += .001;
	else if (key == XK_4)
		sign->av2 -= .001;
	else if (key == XK_5)
		sign->av3 -= .001;
	else if (key == XK_m)
	{
		sign->name = "Mandelbrot";
		sign->iter = 20;
		ft_render(sign, 0);
	}
	else if (key == XK_j)
	{
		sign->name = "Julia";
		sign->av2 = .35;
		sign->av3 = .35;
		ft_render(sign, 0);
	}
	else if (key == XK_p)
	{
		sign->name = "Phoenix";
		sign->av2 = .269;
		sign->av3 = 0;
		sign->av4 = -.01;
		sign->iter = 20;
		ft_render(sign, 0);
	}
	else if (key == XK_Up || key == XK_Down || key == XK_Left || key == XK_Right
		|| key == XK_w || key == XK_s || key == XK_a || key == XK_d)
		ft_moving(key, sign);
	else if (key == XK_t)
	{
		if ((!ft_strcmp(sign->name, "Mandelbrot")))
		{
			sign->iter = 0;
			for (int i = 0; i < 100; i++){
				sign->iter += 1;
				sign->r += i * 5;
				sign->g += i * 5;
				sign->b += i * 5;
				
				int sleep = abs(20000 - ft_power(i, 3));
				usleep(sleep);
				ft_image(sign, 1);
				
			}
			return 0;
		}
	}
	else if (key == XK_y)
	{
		if ((!ft_strcmp(sign->name, "Mandelbrot")))
		{
			// printf("iter: %i\n", sign->iter);
			for (int i = sign->iter; i > 1; i--){
				sign->iter -= 1;
				sign->r -= i * 3;
				sign->g -= i * 3;
				sign->b -= i * 3;
				
				int sleep = abs(20000 - ft_power(i, 3));
				usleep(sleep);
				ft_image(sign, 1);
				
			}
			return 0;
		}
	}
	ft_image(sign, 0);
	return (0);
}

int	ft_mouse_events(int action, int x, int y, t_fractol *sign)
{
	int	temp_x;
	int	temp_y;

	temp_x = (x - (WIDTH / 2)) * 0.1;
	temp_y = (y - (HEIGHT / 2)) * 0.1;
	if (action == SCRP)
		ft_destroy(sign);
	if (action == SCRU || action == SCRD)
		ft_zooming(action, sign, temp_x, temp_y);
	return (0);
}

int		mouse_hover(int x, int y, t_fractol *frac)
{
	if (!ft_strcmp("Julia", frac->name)){
		double coord_x = ft_scale(x, -1, 1, WIDTH);
		double coord_y = ft_scale(y, -1, 1, HEIGHT);
		frac->av2 =  coord_x;
		frac->av3 =  coord_y;
		// printf("julia real: %f\njulia imaginary: %f\n", frac->av2,frac->av3);
		// frac->r += (int)fabs((coord_x * 2) % 255 + coord_y);
		// frac->g += (int)(coord_x * 2) % 255 - coord_y;
		ft_image(frac, 1);
	}
	return 0;
}

void	ft_hooking(t_fractol *comm)
{
	mlx_hook(comm->win, 02, 1L << 0, ft_key_pressed, comm);
	mlx_mouse_hook(comm->win, ft_mouse_events, comm);
	mlx_hook(comm->win, 06, 1L<<6, mouse_hover, comm);
	mlx_hook(comm->win, 17, 0L, ft_destroy, comm);
	// mlx_hook(comm->inst, 17, 0L, ft_destroy_inst, comm);
	mlx_loop(comm->mlx);
}
