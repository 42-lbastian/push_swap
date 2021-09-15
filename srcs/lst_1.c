/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Bastian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 16:05:04 by Bastian           #+#    #+#             */
/*   Updated: 2021/09/09 09:46:52 by Bastian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lst.h"

void	ft_lstclear(t_list **lst)
{
	t_list *temp;

	while (*lst)
	{
		temp = (*lst)->next;
		free(*lst);
		(*lst) = temp;
	}
}

void	ft_lstdelone(t_list **lst)
{
	if (!(*lst)->next && !(*lst)->prev)
		(*lst) = NULL;
	else
	{
		if ((*lst)->prev)
			(*lst)->prev->next = (*lst)->next;
		else
			((*lst)->next->prev = NULL);
		if ((*lst)->next)
			(*lst)->next->prev = (*lst)->prev;
		else
			((*lst)->prev->next = NULL);
		if ((*lst)->next)
			(*lst) = (*lst)->next;
		else
			(*lst) = (*lst)->prev;
	}
}

void ft_lstadd_front(t_list **lst, t_list *new)
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

t_list *ft_lstlast(t_list *lst)
{
	if (!(lst))
		return (lst);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_list *ft_lstfront(t_list *lst)
{
	if (!(lst))
		return (lst);
	while (lst->prev)
		lst = lst->prev;
	return (lst);
}

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

int ft_lstsize(t_list *lst)
{
	int size;

	size = 0;
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}

t_list *ft_lstnew(int content, int pivot)
{
	t_list *new;

	new = malloc(sizeof(t_list));
	if (!(new))
		return (NULL);
	new->content = content;
	new->pivot = pivot;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}
