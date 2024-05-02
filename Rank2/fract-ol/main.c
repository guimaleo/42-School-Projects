#include "./include/fractol.h"

static t_fractol	ft_start_static(void)
{
	static t_fractol	mlx_holder;

	mlx_holder = ft_mlx_communication(WIDTH, HEIGHT, &mlx_holder);
	mlx_holder.r = 1;
	mlx_holder.g = 1;
	mlx_holder.b = 1;
	mlx_holder.zoom = 1.0;
	mlx_holder.iter = MAX_ITER;

	return (mlx_holder);
}

static void	ft_simple_parser(int ac, char **av)
{
	bool	go;

	go = true;
	if (ac < 2 || ac == 3)
		go = false;
	if (!ft_strncmp(av[1], "Mandelbrot", ft_strlen("Mandelbrot")))
	 {
	 	if (ac != 2)
	 		go = false;
	 }
	else if (!ft_strncmp(av[1], "Julia", ft_strlen("Julia")))
	{
		if (ac != 4)
			go = false;
	}
	else if (!ft_strncmp(av[1], "Phoenix", ft_strlen("Phoenix")))
	{
		if (ac != 5)
			go = false;
	}
	else
		go = false;
	if (!go)
		ft_print_instructions();
}
int	main(int ac, char **av)
{
	t_fractol	mlx_holder;

	if (ac < 2 || ac == 3 || ac > 5)
		ft_print_instructions();
	ft_simple_parser(ac, av);
	{
		mlx_holder = ft_start_static();
		if (ac == 4 || ac == 5)
		{
			mlx_holder.av2 = ft_atof(av[2]);
			mlx_holder.av3 = ft_atof(av[3]);
			if (ac == 5)
				mlx_holder.av4 = ft_atof(av[4]);
		}
		mlx_holder.name = av[1];
		//ft_text_inst(&mlx_holder);
		ft_image(&mlx_holder, 1);
		ft_hooking(&mlx_holder);
		return (0);
	}
}
