/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Bastian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 10:43:16 by Bastian           #+#    #+#             */
/*   Updated: 2021/09/09 16:10:48 by Bastian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/operations.h"
#include "../includes/lst.h"
#include "../includes/tools.h"


int ft_sa_sb(t_list **lst, char *str)
{
	int content;
	
	if ((!(*lst)) || (*lst)->next == NULL)
		return (1);
	content = (*lst)->content;
	(*lst)->content = (*lst)->next->content;
	(*lst)->next->content = content;
	write(1, str, ft_strlen(str));
	return (0);
}

int ft_ss(t_list **lst_a, t_list **lst_b)
{
	if (ft_sa_sb(lst_a, "") || ft_sa_sb(lst_b, "ss\n"))
		return (1);
	return (0);
}

int	ft_pa_pb(t_list **lst_1, t_list **lst_2, char *str)
{
	if (!(lst_2))
		return (1);
	ft_lstadd_front(lst_1, ft_lstnew((*lst_2)->content, (*lst_2)->pivot));
	ft_lstdelone(lst_2);
	write(1, str, ft_strlen(str));
	return (0);	
}

int ft_ra_rb(t_list **lst, char *str)
{
	int value;

	if (!((*lst)->next))
		return (1);
	value = (*lst)->content;
	while ((*lst)->next)
	{
		(*lst)->content = (*lst)->next->content;
		(*lst) = (*lst)->next;
	}
	(*lst)->content = value;
	while ((*lst)->prev)
		(*lst) = (*lst)->prev;
	write(1, str, ft_strlen(str));
	return (0);
}

int ft_rr(t_list **lst_a, t_list **lst_b)
{
	if (ft_ra_rb(lst_a, "") || ft_ra_rb(lst_b, "rr\n"))
		return (1);
	return (0);
}

int ft_rra_rrb(t_list **lst, char *str)
{
	int value;

	if (!((*lst)->next))
		return (1);
	while ((*lst)->next)
		(*lst) = (*lst)->next;
	value = (*lst)->content;
	while ((*lst)->prev)
	{
		(*lst)->content = (*lst)->prev->content;
		(*lst) = (*lst)->prev;
	}
	(*lst)->content = value;
	write(1, str, ft_strlen(str));
	return (0);
}

int ft_rrr(t_list **lst_a, t_list **lst_b)
{
	if (ft_rra_rrb(lst_a, "") || ft_rra_rrb(lst_b, "rrr\n"))
		return (1);
	return (0);
}
