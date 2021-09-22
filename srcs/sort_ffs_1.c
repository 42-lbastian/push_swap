/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ffs_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Bastian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 14:45:50 by Bastian           #+#    #+#             */
/*   Updated: 2021/09/22 13:15:57 by lbastian         ###   ########.fr       */
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

void	ft_sort_four(t_list **lst_a, t_list **lst_b)
{
	ft_give_index_numb(lst_a, 0);
	ft_pa_pb(lst_b, lst_a, PB);
	ft_sort_three_a_main(lst_a);
	ft_pa_pb(lst_a, lst_b, PA);
}

void	ft_sort_five(t_list **lst_a, t_list **lst_b)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		if ((*lst_a)->index == 0 || (*lst_a)->index == 1)
		{
			ft_pa_pb(lst_b, lst_a, PB);
			i++;
		}
		else
			ft_ra_rb(lst_a, RA);
	}
	ft_sort_three_a_main(lst_a);
	if ((*lst_b)->content < (*lst_b)->next->content)
		ft_sa_sb(lst_b, SB);
	ft_pa_pb(lst_a, lst_b, PA);
	ft_pa_pb(lst_a, lst_b, PA);
}

void	ft_sort_ffs(t_list **lst_a, t_list **lst_b, int nb)
{
	if (nb == 4)
		ft_sort_four(lst_a, lst_b);
	if (nb == 5)
		ft_sort_five(lst_a, lst_b);
}
