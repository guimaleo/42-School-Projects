/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lede-gui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 11:26:25 by lede-gui          #+#    #+#             */
/*   Updated: 2023/10/16 13:25:43 by lede-gui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*curr;

	if (!del || !lst)
		return ;
	while (*lst)
	{
		curr = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = curr;
	}
}
/*
t_list	*append(t_list **root, int value)
{
	t_list	*new;
	t_list	*curr;

	new = malloc(sizeof(t_list));
	if (!new)
	{
		free(new);
		return (NULL);
	}
	new->content = malloc(sizeof(int));
	if (!new->content)
	{
		free(new->content);
		free(new);
		return (NULL);
	}
	*(int *)(new->content) = value;
	new->next = NULL;
	curr = *root;
	while (curr->next)
		curr = curr->next;
	curr->next = new;
	return (new);
}

void	free_willy(void *willy)
{
	free(willy);
}

int	main()
{
	int	arr[] = {1, 2, 3, 4, 5};
	t_list	*root, *head;

	root = malloc(sizeof(t_list));
	if (!root)
		return (1);
	root->content = malloc(sizeof(int));
	if (!root->content)
	{
		free(root->content);
		free(root);
		return (1);
	}
	*(int *)(root->content) = arr[0];
	root->next = NULL;
	head = root;
	printf("*Head: %p\n*Root: %p\n", head, root);
	printf("*Head: %p\n", head->next);
	int	i = 0;
	while ((size_t)i < sizeof(arr) / sizeof(int))
	{
		root = append(&root, arr[i]);
		printf("Address *(root[%i]): %p\nValue in the node
	       		%i\n", i, root, *(int *)(root->content));
		i++;
	}
	printf("*Head: %p\n*Root: %p\n", head->next, root);
	ft_lstclear(&head, free_willy);
	printf("Nodes cleared!\n");
}*/
