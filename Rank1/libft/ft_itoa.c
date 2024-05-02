/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lede-gui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 20:08:56 by lede-gui          #+#    #+#             */
/*   Updated: 2023/10/16 14:02:52 by lede-gui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	case_negative(char *str, int n, int len)
{
	if (n < 0)
	{
		if (n == -2147483648)
		{
			str[len - 1] = 56;
			n = -214748364;
			len -= 1;
		}
		n *= -1;
		while (len > 1)
		{
			str[0] = 45;
			str[--len] = (n % 10) + 48;
			n /= 10;
		}
	}
}

void	case_positive(char *str, int n, int len)
{
	while (n > 0)
	{
		str[--len] = (n % 10) + 48;
		n /= 10;
	}
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		aux;

	aux = n;
	len = 0;
	if (n <= 0)
		len = 1;
	while (aux)
	{
		aux /= 10;
		len++;
	}
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[len] = 0;
	if (n > 0)
		case_positive(str, n, len);
	else if (n < 0)
		case_negative(str, n, len);
	else
		str[0] = 48;
	return (str);
}
/*
int	main()
{
	int	n = -2147483648;
	char	*s = ft_itoa(n);
	char	s2[] = "-2147483648";
	printf("%s\n", s);
	printf("%lu\n %lu\n", sizeof(s2), ft_strlen(s));
}*/
