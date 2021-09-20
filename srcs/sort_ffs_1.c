/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ffs_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Bastian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 14:45:50 by Bastian           #+#    #+#             */
/*   Updated: 2021/09/20 16:31:07 by Bastian          ###   ########.fr       */
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

void	ft_ope_biggest(t_list **lst_a, t_list **lst_b)
{
	ft_right_order(lst_a);
	ft_pa_pb(lst_a, lst_b, PA);
	ft_ra_rb(lst_a, RA);
}

void	ft_sort_ffs(t_list **lst_a, t_list **lst_b, int nb)
{
	ft_pa_pb(lst_b, lst_a, PB);
	if (nb > 4)
		ft_pa_pb(lst_b, lst_a, PB);
	if (nb > 5)
		ft_pa_pb(lst_b, lst_a, PB);
	if (!(ft_list_is_sort((*lst_a))))
		ft_sort_three_a_main(lst_a);
	if (!(ft_list_is_sort((*lst_b))))
	{
		if (nb == 5)
			ft_sa_sb(lst_b, SB);
		if (nb == 6)
			ft_sort_three_b_main(lst_b);
	}
	while ((*lst_b))
	{
		if (ft_is_the_biggest((*lst_b)->content, (*lst_a)))
			ft_ope_biggest(lst_a, lst_b);
		while ((*lst_a)->content < (*lst_b)->content
			&& !(ft_is_the_biggest((*lst_b)->content, (*lst_a))))
			ft_ra_rb(lst_a, RA);
		ft_pa_pb(lst_a, lst_b, PA);
	}
	ft_right_order(lst_a);
}
