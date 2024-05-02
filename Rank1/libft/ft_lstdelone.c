/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lede-gui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:13:52 by lede-gui          #+#    #+#             */
/*   Updated: 2023/10/16 13:05:28 by lede-gui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst && !del)
		return ;
	del(lst->content);
	free(lst);
}
/*
int	main(void)
{
	int	arr[] = {1, 2, 3, 4, 5};
	t_list	*list;
	t_list	*new;

	list = ft_lstnew(arr);
	int	i = 1;
	while ((size_t)i < sizeof(arr) / sizeof(arr[0]))
	{
		new = ft_lstnew(arr + i);
		ft_lstadd_front(&list, new);
		i++;
	}
	ft_lstdelone(list, free);
}*/
