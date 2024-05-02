/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lede-gui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 18:46:26 by lede-gui          #+#    #+#             */
/*   Updated: 2023/10/16 19:48:28 by lede-gui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libftprintf.h"
#include <stdio.h>
int	main()
{
	int	x;
	char	*str = NULL;

	x = 57;
	ft_printf("Write Only\n");
	ft_printf("Write a integer: %i\n", -2147483648);
	ft_printf("Write another integer: %d\n", 2147483647);
	ft_printf("Write a string: %s\n", "va_args is interesting!");
	ft_printf("Write an unsigned int: %u\n", 2222222222);
	ft_printf("Write a character: %c\n", 'H');
	ft_printf("Write a %% sign: %%\n");
	ft_printf("Write an adress: %p\n", &x);
	ft_printf("Original address: %p\n", &x);
	ft_printf("%p\n", str);
	printf("%p\n", str);
	ft_printf("Custom null test: %i\n", ft_printf(NULL));
	printf("%i\n", printf("Original null test: %i\n" ,printf(NULL)));
}
