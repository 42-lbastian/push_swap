/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Bastian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 16:05:04 by Bastian           #+#    #+#             */
/*   Updated: 2021/10/01 15:26:30 by Bastian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lst.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*temp;

	while (*lst)
	{
		temp = (*lst)->next;
		free(*lst);
		(*lst) = temp;
	}
}

void	ft_lstdelone(t_list **lst)
{
	t_list	*prev;
	t_list	*next;

	if (lst == NULL || *lst == NULL)
		return ;
	prev = (*lst)->prev;
	next = (*lst)->next;
	if (!(*lst)->next && !(*lst)->prev)
	{
		free(*lst);
		(*lst) = NULL;
	}	
	else
	{
	//	next->prev = NULL;
	//	prev->next = NULL;
		if (prev)
			prev->next = next;
		if (next)
			next->prev = prev;
		free(*lst);
		if (next)
			(*lst) = next;
		else
			(*lst) = prev;
	}
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if ((lst) && (*lst))
	{
		(*lst)->prev = new;
		new->next = *lst;
		new->prev = NULL;
		*lst = new;
	}
	else
		(*lst) = new;
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!(lst))
		return (lst);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_list	*ft_lstfront(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->prev)
		lst = lst->prev;
	return (lst);
}
