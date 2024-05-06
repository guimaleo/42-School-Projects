/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lede-gui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 17:27:21 by lede-gui          #+#    #+#             */
/*   Updated: 2023/10/13 17:58:02 by lede-gui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

/*
void	upper(unsigned int i, char *s)
{
	*s = ft_toupper(*s);
	printf("In upper: %s\n", s);
}

int	main()
{
	char	str[] = "abcde!";
	char	*res;

	res = ft_strdup(str);
	ft_striteri(res, upper);
	printf("striteri result: %s\n", res);
}*/
