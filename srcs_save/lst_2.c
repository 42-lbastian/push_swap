/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Bastian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 15:25:31 by Bastian           #+#    #+#             */
/*   Updated: 2021/09/20 15:26:24 by Bastian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lst.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if ((lst) && (*lst))
	{
		new->next = NULL;
		new->prev = ft_lstlast(*lst);
		ft_lstlast(*lst)->next = new;
	}
	else
		ft_lstadd_front(lst, new);
}

int	ft_lstsize(t_list *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}

t_list	*ft_lstnew(int content, int pivot)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!(new))
		return (NULL);
	new->content = content;
	new->pivot = pivot;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}
