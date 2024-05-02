/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lede-gui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 09:17:26 by lede-gui          #+#    #+#             */
/*   Updated: 2023/10/13 16:51:20 by lede-gui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list	*swap;

	if (!new)
		return ;
	swap = *lst;
	*lst = new;
	new->next = swap;
}
/*
int	main(void)
{
	t_list	*p_arr;
	t_list	*p_arr2;
	t_list	*p_str;
	t_list	*p_str2;
	t_list	*index_arr;
	int	arr[5] = {1, 2, 3, 4, 5};
	int	arr2[5] = {6, 7, 8, 9, 10};
	char	str[] = "Batatinha quando nasce";
	char	str2[] = " espalha rama pelo chao";
	int	i = 0;
	t_list	*save;
	p_arr = ft_lstnew(arr);
	p_arr2 = ft_lstnew(arr2);
	p_str = ft_lstnew(str);
	p_str2 = ft_lstnew(str2);
	ft_lstadd_front(&p_arr, p_arr2);
	ft_lstadd_front(&p_str2, p_str);
	index_arr = p_arr;
	while (index_arr)
	{
		save = index_arr;
		i = 0;
		while(i < 5)
		{
			printf("arr[%i]: %i\n", i, ((int *)index_arr->content)[i]);
			i++;
		}
		index_arr = index_arr->next;
	}
	printf("\033[1;31mCUIDADO!!!\033[0m\np_arr2 address: %p\n", p_arr2);
	printf("\033[1;31mCUIDADO!!!\033[0m\np_arr address: %p\n", p_arr);
	free(p_arr2->next);
	free(p_arr2);
	index_arr = p_str2;
	i = 0;
	while (index_arr)
	{
		printf("str[%i]: %s\n", i, (char *)index_arr->content);
		index_arr = index_arr->next;
		i++;
	}
	printf("\033[1;31mCUIDADO!!!\033[0m\np_arr2 address: %p\n", p_str2);
	printf("\033[1;31mCUIDADO!!!\033[0m\np_arr address: %p\n", p_str);
	free(p_str2->next);
	free(p_str);
	printf("\n\033[1;34mSe chegamos aqui, FREE WILLY!!!\033[0m\n");
	return (0);
}*/
