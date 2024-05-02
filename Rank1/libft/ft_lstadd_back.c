/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lede-gui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 20:16:16 by lede-gui          #+#    #+#             */
/*   Updated: 2023/10/16 13:03:50 by lede-gui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*curr;

	if (!new)
		return ;
	if (!(*lst))
		*lst = new;
	else
	{
		curr = ft_lstlast(*lst);
		curr->next = new;
	}
}
/*
void	free_willy(void *willy)
{
	free(willy);
}

int	*creat_int_ptr(int n)
{
	int	*x;

	x = (int *)malloc(sizeof(int));
	if (!x)
		return (NULL);
	*x = n;
	return (x);
}

int	main(int ac, char **av)
{
	t_list	*head;
	t_list	*save;

	if (ac > 1)
	{
		while ((++av, *av))
			ft_lstadd_back(&head, ft_lstnew(creat_int_ptr(ft_atoi(*av))));

		printf("content: ");
		save = head;
		while (head)
		{
			if (head->next)
				printf("%i -> ", *(int*)head->content);
			else
				printf("%i\n", *(int*)head->content);
			head = head->next;
		}
		ft_lstclear(&save, free);
	}
	else
		printf("Usage: ./a.out {integers}.");
}*/
