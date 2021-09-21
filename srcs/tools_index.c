/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_index.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Bastian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 11:46:49 by Bastian           #+#    #+#             */
/*   Updated: 2021/09/21 11:55:48 by Bastian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lst.h"

int		ft_how_many_less(t_list *lst, int nb)
{
	int compt;

	compt = 0;
	while (lst)
	{
		if (lst->content < nb)
			compt++;
		lst = lst->next;
	}
	return (compt);
}

void	ft_add_index(t_list **lst)
{
	while ((*lst)->next)
	{
		(*lst)->index = ft_how_many_less(ft_lstfront((*lst)), (*lst)->content);
		(*lst) = (*lst)->next;
	}
	(*lst)->index = ft_how_many_less(ft_lstfront((*lst)), (*lst)->content);
	(*lst) = ft_lstfront((*lst));
}
