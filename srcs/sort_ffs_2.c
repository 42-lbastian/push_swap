/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ffs_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Bastian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 15:56:55 by Bastian           #+#    #+#             */
/*   Updated: 2021/09/20 16:20:59 by Bastian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lst.h"
#include "../includes/sort_ffs.h"
#include "../includes/operations.h"

void	ft_sort_three_a_1(t_list **lst)
{
	if ((*lst)->content < (*lst)->next->content && (*lst)->next->content
		> (*lst)->next->next->content && (*lst)->content
		< (*lst)->next->next->content)
	{
		ft_sa_sb(lst, SA);
		ft_ra_rb(lst, RA);
	}
	if ((*lst)->content > (*lst)->next->content && (*lst)->next->content
		< (*lst)->next->next->content && (*lst)->content
		< (*lst)->next->next->content)
		ft_sa_sb(lst, SA);
	if ((*lst)->content < (*lst)->next->content && (*lst)->next->content
		> (*lst)->next->next->content && (*lst)->content
		> (*lst)->next->next->content)
		ft_rra_rrb(lst, RRA);
}

void	ft_sort_three_a_2(t_list **lst)
{
	if ((*lst)->content > (*lst)->next->content && (*lst)->next->content
		< (*lst)->next->next->content && (*lst)->content
		> (*lst)->next->next->content)
		ft_ra_rb(lst, RA);
	if ((*lst)->content > (*lst)->next->content && (*lst)->next->content
		> (*lst)->next->next->content && (*lst)->content
		> (*lst)->next->next->content)
	{
		ft_sa_sb(lst, SA);
		ft_rra_rrb(lst, RRA);
	}
}

void	ft_sort_three_a_main(t_list **lst)
{
	ft_sort_three_a_1(lst);
	ft_sort_three_a_2(lst);
}
