/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lede-gui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 20:37:14 by lede-gui          #+#    #+#             */
/*   Updated: 2024/04/30 20:37:17 by lede-gui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "./minilibx-linux/mlx.h"
# include "./minilibx-linux/mlx_int.h"
# include "./ft_printf/includes/libftprintf.h"
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <math.h>
# include <unistd.h>
# include <string.h>
# include <stdbool.h>

/*--------------------------------------------------------------------------*/

typedef struct s_fractol
{
	void	*mlx;
	void	*win;
	char	*name;
	char	*addr;
	void	*img;
	int		height;
	int		width;
	int		bpp;
	int		endian;
	int		line_len;
	int		r;
	int		g;
	int		b;
	int		x_coord;
	int		x_0;
	int		y_0;
	int		y_coord;
	int		iter;
	float	av2;
	float	av3;
	float	av4;
	double	zoom;
	bool	flag;
	// char	*text[8];
	// void	*inst;
}		t_fractol;

typedef struct s_complex
{
	double	real;
	double	imag;
}		t_complex;

/*---------------------------------------------------------------------------*/

# define HEIGHT 800
# define WIDTH 800
# define MAX_ITER 1 // ???
# define KC 0.001
# define SCALER 0.1
# define XMIN 0.0
# define YMIN 0.0

/*---------------------------------------------------------------------------*/

# define ESC 65307
# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363
# define NUMPLUS 65451
# define NUMMINUS 65453
# define NUMDOT 65439
# define DOT 46
# define MINUS 45
# define PLUS 61
# define IT 105
# define SPC 32
# define W_K 119
# define A_K 97
# define S_K 115
# define D_K 100
# define SHIFT 65505
# define R 114
# define G 103
# define B 98

/*---------------------------------------------------------------------------*/

# define RCL 3
# define LCL 1
# define SCRU 4
# define SCRD 5
# define SCRP 2

/*---------------------------------------------------------------------------*/

/*MLX WORLD*/

t_fractol	ft_mlx_communication(int width, int height, t_fractol *comm);
int			ft_destroy(t_fractol *window);
int			ft_destroy_inst(t_fractol *inst);

/*CANVAS WORLD*/

void		ft_pixel_put(t_fractol *canvas, int x, int y, int color);
void		ft_image(t_fractol *mlx, int control);
void		ft_render(t_fractol *canvas, int color);
int			ft_color_choose(int i, t_fractol *canvas);
int			ft_fractal_choice(t_fractol *frac, t_complex c);
int			ft_mandelbrot(t_complex c, t_fractol *frac);
int			ft_julia(t_complex z, t_fractol *frac);
int			ft_phoenix(t_complex z, t_fractol *frac);

/*EVENT WORLD*/

int			ft_key_pressed(int key, t_fractol *sign);
int			ft_mouse_events(int action, int x, int y, t_fractol *sign);
void		ft_hooking(t_fractol *comm);

/*STRINGS AND ERRORS*/

void		ft_print_instructions(void);
size_t		ft_strlen(char *s);
void		ft_error(char *s);
size_t		ft_strcmp(char *s1, char *s2);
void		ft_text_inst(t_fractol *txt);

/*MATH UTILS*/

double		ft_scale(double to_scale, double new_min, \
double new_max, double old_max);
float		ft_atof(char *s);

#endif
