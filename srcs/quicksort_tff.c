/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_tff.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 12:55:34 by lbastian          #+#    #+#             */
/*   Updated: 2021/09/22 13:13:19 by lbastian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lst.h"
#include "../includes/sort_ffs.h"
#include "../includes/operations.h"
#include "../includes/tools.h"

void	ft_quick_three(t_list **lst_a, t_list **lst_b)
{
	(*lst_a)->pivot = 1;
	(*lst_a)->next->pivot = 1;
	(*lst_a)->next->next->pivot = 1;
	ft_sort_three_a_main(lst_a);
	ft_pa_pb(lst_b, lst_a, PB);
	ft_pa_pb(lst_b, lst_a, PB);
	ft_pa_pb(lst_b, lst_a, PB);
}

void	ft_quick_four(t_list **lst_a, t_list **lst_b)
{
	while ((*lst_a)->next)
	{
		(*lst_a)->pivot = 1;
		(*lst_a) = (*lst_a)->next;
	}
	(*lst_a)->pivot = 1;
	(*lst_a) = ft_lstfront((*lst_a));
	ft_give_index_numb(lst_a, ft_little_index((*lst_a)));
	ft_pa_pb(lst_b, lst_a, PB);
	ft_sort_three_a_main(lst_a);
	ft_pa_pb(lst_b, lst_a, PB);
	ft_pa_pb(lst_b, lst_a, PB);
	ft_pa_pb(lst_b, lst_a, PB);
}

void	ft_quick_five(t_list **lst_a, t_list **lst_b)
{
	while ((*lst_a)->next)
	{
		(*lst_a)->pivot = 1;
		(*lst_a) = (*lst_a)->next;
	}
	(*lst_a)->pivot = 1;
	(*lst_a) = ft_lstfront((*lst_a));
	ft_give_index_numb(lst_a, ft_little_index((*lst_a)));
	ft_pa_pb(lst_b, lst_a, PB);
	ft_give_index_numb(lst_a, ft_little_index((*lst_a)));
	ft_pa_pb(lst_b, lst_a, PB);
	if ((*lst_b)->content < (*lst_b)->next->content)
		ft_sa_sb(lst_b, SB);
	ft_sort_three_a_main(lst_a);
	ft_pa_pb(lst_b, lst_a, PB);
	ft_pa_pb(lst_b, lst_a, PB);
	ft_pa_pb(lst_b, lst_a, PB);
}

void	ft_quick_magic(t_list **lst_a, t_list **lst_b)
{
	int	pivot;

	while ((*lst_a))
	{
		ft_give_numb(lst_a, ft_calc_mediane((*lst_a)));
		pivot = (*lst_a)->content;
		(*lst_a)->pivot = 1;
		if ((*lst_a)->next)
		{
			ft_ra_rb(lst_a, RA);
			while ((*lst_a)->pivot == 0)
			{
				if ((*lst_a)->content < pivot)
					ft_pa_pb(lst_b, lst_a, PB);
				else
					ft_ra_rb(lst_a, RA);
			}
		}
		ft_pa_pb(lst_b, lst_a, PB);
	}
}
