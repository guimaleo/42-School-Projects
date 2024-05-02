/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lede-gui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 17:20:36 by lede-gui          #+#    #+#             */
/*   Updated: 2023/10/13 17:25:55 by lede-gui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*curr;
	t_list	*res;

	if (!lst || !f || !del)
		return (NULL);
	res = NULL;
	while (lst)
	{
		curr = ft_lstnew(f(lst->content));
		if (curr == NULL)
		{
			ft_lstclear(&res, free);
			return (NULL);
		}
		ft_lstadd_back(&res, curr);
		lst = lst->next;
	}
	return (res);
}
