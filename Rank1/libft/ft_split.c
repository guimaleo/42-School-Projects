/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lede-gui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 19:31:29 by lede-gui          #+#    #+#             */
/*   Updated: 2023/10/15 12:17:06 by lede-gui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_words(char const *str, char c)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (*str != c)
		{
			while (*str && *str != c)
				str++;
			count ++;
		}
		if (!*str)
			break ;
		str++;
	}
	return (count);
}

int	ft_len(const char *s, char d)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != d)
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		words;
	int		i;

	words = count_words(s, c);
	res = (char **)malloc((words + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	res[words] = 0;
	i = 0;
	while (words > 0)
	{
		while (*s == c)
			s++;
		res[i] = ft_substr(s, 0, ft_len(s, c));
		if (!res)
			break ;
		s += ft_len(s, c);
		words--;
		i++;
	}
	return (res);
}
/*
int	main()
{
	char	str[] = "  Split geralmente tem problema no count words!       ";
	printf("%i\n", count_words(str, 32));
	int	i = 0;
	char	**split;
	split = ft_split(str, 32);
	while (split[i])
	{
		printf("str[%i]: %s\n", i, split[i]);
		free(split[i]);
		i++;
	}
	free(split);
}*/
