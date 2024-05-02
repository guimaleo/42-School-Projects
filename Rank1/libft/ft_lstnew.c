/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lede-gui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 22:43:59 by lede-gui          #+#    #+#             */
/*   Updated: 2023/10/09 09:16:42 by lede-gui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}
/*
int	main(void)
{
	char	str[] = "I HAVE NODES COMPLEXES!";
	int	test[] = {42, 23, 54};
	t_list	*hodor, *willy;
	int	i;
	int	*aux;

	i = 0;
	hodor = NULL;
	willy = NULL;
	hodor = ft_lstnew(str);
	willy = ft_lstnew(test);
	printf("%s\n", (char *)hodor->content);
	aux = (int *)willy->content;
	while (i < 3)
		printf("%i\n", aux[i++]);
	free(hodor);
	free(willy);
}*/
