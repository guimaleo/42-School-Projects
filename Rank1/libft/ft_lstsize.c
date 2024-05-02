/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lede-gui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:59:11 by lede-gui          #+#    #+#             */
/*   Updated: 2023/10/13 16:12:20 by lede-gui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*iterator;
	int		i;

	i = 0;
	if (!lst)
		return (0);
	iterator = lst;
	while (iterator)
	{
		i++;
		iterator = iterator->next;
	}
	return (i);
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
		free(new);
		return (NULL);
	}
	*(int *)(new->content) = value;
	new->next = NULL;
	curr = *root;
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = new;
	return (new);
}

void	free_willy(void *willy)
{
	free(willy);
}

int	main(void)
{
	int	arr[] = {1, 2, 3, 4, 5};
	t_list	*root;
	t_list	*head;

	root = malloc(sizeof(t_list));
	if (!root)
		return (1);
	root->content = malloc(sizeof(int));
	if (!root->content)
	{
		free(root);
		return (1);
	}
	*(int *)(root->content) = arr[0];
	root->next = NULL;
	head = root;
	int	i = 1;
	while ((unsigned long)i < sizeof(arr) / sizeof(int))
	{
		root = append(&root, arr[i]);
		i++;
	}
	printf("%i\n%i\n", i,  ft_lstsize(head));
	t_list	*aux;
	aux = head;
	i = 0;
	while (aux != NULL)
	{
		printf("arr[%i]: %i\n", i, *(int *)(aux->content));
		aux = aux->next;
		i++;
	}
	ft_lstclear(&head, free_willy);
}*/
