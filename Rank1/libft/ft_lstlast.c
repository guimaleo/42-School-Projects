/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lede-gui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:59:13 by lede-gui          #+#    #+#             */
/*   Updated: 2023/10/13 17:16:00 by lede-gui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
/*
int	main(void)
{
	int	arr[] = {1, 2, 3, 4, 5};
	t_list	*list;
	t_list	*first;
	t_list	*head;
	t_list	*res;
	t_list	*new;
	int	i;

	list = NULL;
	i = 1;
	list = ft_lstnew(arr);
	head = list;
	printf("%p\n%p\n", head, first);
	while ((size_t)i < sizeof(arr) / sizeof(arr[0]))
	{
		new = ft_lstnew(arr + i);
		ft_lstadd_back(&list, new);
		i++;
	}
	res = ft_lstlast(list);
	printf("res: %p\nhead:%p\n", res, head);
	printf("%i\n", *(int *)res->content);
	ft_lstclear(&head, free);
}*/
