/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lede-gui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:05:51 by lede-gui          #+#    #+#             */
/*   Updated: 2023/10/04 14:34:13 by lede-gui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int	ft_memory_tester(int x);

int	main()
{

	if ((ft_isalpha(1) == isalpha(1)) && (ft_isalpha('a') == isalpha('a')))
		printf("ft_isalpha: \033[1;36mOK\033[0m\n");
	else
		printf("ft_isalpha: \033[1;35mKO\033[0m\n");
	if ((ft_isalnum(1) == isalnum(1)) && (ft_isalnum('B') == isalnum ('B')))
		printf("ft_isalnum: \033[1;36mOK\033[0m\n");
	else
		printf("ft_isalnum: \033[1;35mKO\033[0m\n");
	if ((ft_isascii(1) == isascii(1)) && (ft_isascii(126) == isascii(126)))
		printf("ft_isascii: \033[1;36mOK\033[0m\n");
	else
		printf("ft_isascii: \033[1;35mKO\033[0m\n");
	if ((ft_isdigit(48) == isdigit(48)) && (ft_isdigit('0') == isdigit('0')))
		printf("ft_isdigit: \033[1;36mOK\033[0m\n");
	else
		printf("ft_isdigit: \033[1;35mKO\033[0m\n");
	if ((ft_isprint(35) == isprint(35)) && (ft_isprint(112) == isprint(112)))
		printf("ft_isprint: \033[1;36mOK\033[0m\n");
	else
		printf("ft_isprint: \033[1;35mKO\033[0m\n");
	if ((ft_toupper('a') == toupper('a')) && (ft_toupper('z') == toupper('z')))
		printf("ft_toupper: \033[1;36mOK\033[0m\n");
	else
		printf("ft_toupper: \033[1;35mKO\033[0m\n");
	if ((ft_memory_tester(65)))
		printf("ft_memset: \033[1;36mOK\033[0m\n");
	else
		printf("ft_memset: \033[1;35mKO\033[0m\n");
	if (ft_memory_tester(0))
		printf("ft_bzero: \033[1;36mOK\033[0m\n");
	else
		printf("ft_bzero: \033[1;35mKO\033[0m\n");
	/*	if ((ft_isascii(1) == isascii(1)) && (ft_isacii(126) && isascii(126)))
			printf("ft_isascii: \033[1;36mOK\033[0m\n");
		else
			printf("ft_isascii: \033[1;35mKO\033[0m\n");
		if ((ft_isascii(1) == isascii(1)) && (ft_isacii(126) && isascii(126)))
			printf("ft_isascii: \033[1;36mOK\033[0m\n");
		else
			printf("ft_isascii: \033[1;35mKO\033[0m\n");
		if ((ft_isascii(1) == isascii(1)) && (ft_isacii(126) && isascii(126)))
			printf("ft_isascii: \033[1;36mOK\033[0m\n");
		else
			printf("ft_isascii: \033[1;35mKO\033[0m\n");
		if ((ft_isascii(1) == isascii(1)) && (ft_isacii(126) && isascii(126)))
			printf("ft_isascii: \033[1;36mOK\033[0m\n");
		else
			printf("ft_isascii: \033[1;35mKO\033[0m\n");
		if ((ft_isascii(1) == isascii(1)) && (ft_isacii(126) && isascii(126)))
			printf("ft_isascii: \033[1;36mOK\033[0m\n");
		else
			printf("ft_isascii: \033[1;35mKO\033[0m\n");
		if ((ft_isascii(1) == isascii(1)) && (ft_isacii(126) && isascii(126)))
			printf("ft_isascii: \033[1;36mOK\033[0m\n");
		else
			printf("ft_isascii: \033[1;35mKO\033[0m\n");
		if ((ft_isascii(1) == isascii(1)) && (ft_isacii(126) && isascii(126)))
			printf("ft_isascii: \033[1;36mOK\033[0m\n");
		else
			printf("ft_isascii: \033[1;35mKO\033[0m\n");
		if ((ft_isascii(1) == isascii(1)) && (ft_isacii(126) && isascii(126)))
			printf("ft_isascii: \033[1;36mOK\033[0m\n");
		else
			printf("ft_isascii: \033[1;35mKO\033[0m\n");
		if ((ft_isascii(1) == isascii(1)) && (ft_isacii(126) && isascii(126)))
			printf("ft_isascii: \033[1;36mOK\033[0m\n");
		else
			printf("ft_isascii: \033[1;35mKO\033[0m\n");
		if ((ft_isascii(1) == isascii(1)) && (ft_isacii(126) && isascii(126)))
			printf("ft_isascii: \033[1;36mOK\033[0m\n");
		else
			printf("ft_isascii: \033[1;35mKO\033[0m\n");
		if ((ft_isascii(1) == isascii(1)) && (ft_isacii(126) && isascii(126)))
			printf("ft_isascii: \033[1;36mOK\033[0m\n");
		else
			printf("ft_isascii: \033[1;35mKO\033[0m\n");
		if ((ft_isascii(1) == isascii(1)) && (ft_isacii(126) && isascii(126)))
			printf("ft_isascii: \033[1;36mOK\033[0m\n");
		else
			printf("ft_isascii: \033[1;35mKO\033[0m\n");
		if ((ft_isascii(1) == isascii(1)) && (ft_isacii(126) && isascii(126)))
			printf("ft_isascii: \033[1;36mOK\033[0m\n");
		else
			printf("ft_isascii: \033[1;35mKO\033[0m\n");
		if ((ft_isascii(1) == isascii(1)) && (ft_isacii(126) && isascii(126)))
			printf("ft_isascii: \033[1;36mOK\033[0m\n");
		else
			printf("ft_isascii: \033[1;35mKO\033[0m\n");
		if ((ft_isascii(1) == isascii(1)) && (ft_isacii(126) && isascii(126)))
			printf("ft_isascii: \033[1;36mOK\033[0m\n");
		else
			printf("ft_isascii: \033[1;35mKO\033[0m\n");
		if ((ft_isascii(1) == isascii(1)) && (ft_isacii(126) && isascii(126)))
			printf("ft_isascii: \033[1;36mOK\033[0m\n");
		else
			printf("ft_isascii: \033[1;35mKO\033[0m\n");
		if ((ft_isascii(1) == isascii(1)) && (ft_isacii(126) && isascii(126)))
			printf("ft_isascii: \033[1;36mOK\033[0m\n");
		else
			printf("ft_isascii: \033[1;35mKO\033[0m\n");*/
}

int	ft_memory_tester(int x)
{
	void	*p;
	void	*rip;

	p = malloc(10);
	rip = malloc(10);
	if (x != 0)
	{
		if (!p || !rip)
			return (0);
		if (!memcmp(ft_memset(p, x, 10),memset(rip, x, 10), 10))
		{
			free(p);
			free(rip);
			return (1);
		}
		free(p);
		free(rip);
		return (0);
	}
	else
	{
		if(!p || !rip)
			return(0);
		ft_bzero(p, 10);
		bzero(rip, 10);
		if (!memcmp(p, rip, 10))
		{
			free(p);
			free(rip);
			return (1);
		}
		free(p);
		free(rip);
		return (0);

	}
}

