/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ffs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Bastian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 14:45:50 by Bastian           #+#    #+#             */
/*   Updated: 2021/09/20 15:04:15 by Bastian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lst.h"
#include "../includes/operations.h"
#include "../includes/sort_ffs.h"
#include "../includes/tools.h"

int	ft_is_the_biggest(int nb, t_list *lst)
{
	while (lst)
	{
		if (nb < lst->content)
			return (0);
		lst = lst->next;
	}
	return (1);
}

void	ft_sort_three_a(t_list **lst)
{
	if ((*lst)->content < (*lst)->next->content && (*lst)->next->content > (*lst)->next->next->content && (*lst)->content < (*lst)->next->next->content)
	{
		ft_sa_sb(lst, SA);
		ft_ra_rb(lst, RA);
	}
	if ((*lst)->content > (*lst)->next->content && (*lst)->next->content < (*lst)->next->next->content && (*lst)->content < (*lst)->next->next->content)
		ft_sa_sb(lst, SA);
	if ((*lst)->content < (*lst)->next->content && (*lst)->next->content > (*lst)->next->next->content && (*lst)->content > (*lst)->next->next->content)
		ft_rra_rrb(lst, RRA);
	if ((*lst)->content > (*lst)->next->content && (*lst)->next->content < (*lst)->next->next->content && (*lst)->content > (*lst)->next->next->content)
		ft_ra_rb(lst, RA);
	if ((*lst)->content > (*lst)->next->content && (*lst)->next->content > (*lst)->next->next->content && (*lst)->content > (*lst)->next->next->content)
	{
		ft_sa_sb(lst, SA);
		ft_rra_rrb(lst, RRA);
	}
}

void	ft_sort_three_b(t_list **lst)
{
	if ((*lst)->content < (*lst)->next->content && (*lst)->next->content > (*lst)->next->next->content && (*lst)->content < (*lst)->next->next->content)
	{
		ft_sa_sb(lst, SB);
		ft_ra_rb(lst, RB);
	}
	if ((*lst)->content > (*lst)->next->content && (*lst)->next->content < (*lst)->next->next->content && (*lst)->content < (*lst)->next->next->content)
		ft_sa_sb(lst, SB);
	if ((*lst)->content < (*lst)->next->content && (*lst)->next->content > (*lst)->next->next->content && (*lst)->content > (*lst)->next->next->content)
		ft_rra_rrb(lst, RRB);
	if ((*lst)->content > (*lst)->next->content && (*lst)->next->content < (*lst)->next->next->content && (*lst)->content > (*lst)->next->next->content)
		ft_ra_rb(lst, RB);
	if ((*lst)->content > (*lst)->next->content && (*lst)->next->content > (*lst)->next->next->content && (*lst)->content > (*lst)->next->next->content)
	{
		ft_sa_sb(lst, SB);
		ft_rra_rrb(lst, RRB);
	}
}

void	ft_sort_ffs(t_list **lst_a, t_list **lst_b, int nb)
{
	ft_pa_pb(lst_b, lst_a, PB);
	if (nb > 4)
		ft_pa_pb(lst_b, lst_a, PB);
	if (nb > 5)
		ft_pa_pb(lst_b, lst_a, PB);
	if (!(ft_list_is_sort((*lst_a))))
		ft_sort_three_a(lst_a);
	if (!(ft_list_is_sort((*lst_b))))
	{
		if (nb == 5)
			ft_sa_sb(lst_b, SB);
		if (nb == 6)
			ft_sort_three_b(lst_b);
	}
	while ((*lst_b))
	{
		if (ft_is_the_biggest((*lst_b)->content, (*lst_a)))
		{
			ft_right_order(lst_a);
			ft_pa_pb(lst_a, lst_b, PA);
			ft_ra_rb(lst_a, RA);
		}
		while ((*lst_a)->content < (*lst_b)->content && !(ft_is_the_biggest((*lst_b)->content, (*lst_a))))
			ft_ra_rb(lst_a, RA);
		ft_pa_pb(lst_a, lst_b, PA);
	}
	ft_right_order(lst_a);
}
