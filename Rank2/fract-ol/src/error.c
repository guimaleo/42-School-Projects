/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lede-gui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 19:40:49 by lede-gui          #+#    #+#             */
/*   Updated: 2024/04/30 19:43:11 by lede-gui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	ft_error(char *s)
{
	if (!s)
	{
		printf("Unknown error!");
		return ;
	}
	else
	{
		perror(s);
		strerror(errno);
		return ;
	}
}

void	ft_print_instructions(void)
{
	char	*inst;

	inst = "\n\033[1;31mUsage: ./fractol <fractal set> \
	if needed <arg2> <arg3> <arg4>\n\n \
		\033[1;33mMandelbrot -> ./fractol Mandelbrot\n \
		\033[1;35mJulia -> ./fractol Julia <float 1> <float 2>\n \
		\t suggested: .35 .35 or -.8 .156\n\n \
		\033[1;34mPhoenix -> ./fractol Phoenix <float 1> <float 2> <float 3> \n \
		\t suggested: .269 0 -.01 or .269 -.01 -.01 \033[0m \n \
		\t\033[3;37m\n\nInstructions:\n\n\tZoom-> '+' or '-' or Mouse Wheel\n\
	Movement: WASD or Arrow Keys\n\n\
	Colors: R, G or B\n\tColors are made with factors, ask more if wanted!\n\n \
	Enjoy the trip!\t=D\033[0m\n";
	ft_printf("%s", inst);
	exit(EXIT_FAILURE);
}
