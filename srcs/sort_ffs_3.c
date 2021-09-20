/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ffs_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Bastian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 16:06:13 by Bastian           #+#    #+#             */
/*   Updated: 2021/09/20 16:14:27 by Bastian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lst.h"
#include "../includes/sort_ffs.h"
#include "../includes/operations.h"

void	ft_sort_three_b_2(t_list **lst)
{
	if ((*lst)->content < (*lst)->next->content && (*lst)->next->content
		> (*lst)->next->next->content && (*lst)->content
		> (*lst)->next->next->content)
		ft_rra_rrb(lst, RRB);
	if ((*lst)->content > (*lst)->next->content && (*lst)->next->content
		< (*lst)->next->next->content && (*lst)->content
		> (*lst)->next->next->content)
		ft_ra_rb(lst, RB);
	if ((*lst)->content > (*lst)->next->content && (*lst)->next->content
		> (*lst)->next->next->content && (*lst)->content
		> (*lst)->next->next->content)
	{
		ft_sa_sb(lst, SB);
		ft_rra_rrb(lst, RRB);
	}
}

void	ft_sort_three_b_1(t_list **lst)
{
	if ((*lst)->content < (*lst)->next->content && (*lst)->next->content
		> (*lst)->next->next->content && (*lst)->content
		< (*lst)->next->next->content)
	{
		ft_sa_sb(lst, SB);
		ft_ra_rb(lst, RB);
	}
	if ((*lst)->content > (*lst)->next->content && (*lst)->next->content
		< (*lst)->next->next->content && (*lst)->content
		< (*lst)->next->next->content)
		ft_sa_sb(lst, SB);
}

void	ft_sort_three_b_main(t_list **lst)
{
	ft_sort_three_b_1(lst);
	ft_sort_three_b_2(lst);
}
