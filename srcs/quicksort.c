/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Bastian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 15:09:08 by Bastian           #+#    #+#             */
/*   Updated: 2021/09/22 12:36:58 by lbastian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lst.h"
#include "../includes/operations.h"
#include "../includes/sort_ffs.h"
#include "../includes/quicksort.h"
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

int	ft_calc_mediane(t_list *lst)
{
	int nb_big;
	int nb_small;
	int nb;

	nb = lst->content;
	while (lst)
	{
		nb_small = ft_smaller_biggest_element(lst->content, ft_lstfront(lst), 0);
		nb_big = ft_smaller_biggest_element(lst->content, ft_lstfront(lst), 1);
		if (nb_big == nb_small)
		{
			nb = lst->content;
			break;
		}
		if (nb_small + 1 == nb_big)
		{
			nb = lst->content;
			break;
		}
		lst = lst->next;
	}
	return (nb);
}

void	ft_send_a_to_b(t_list **lst_a, t_list **lst_b)
{
	int	pivot;

	if (ft_lstsize((*lst_a)) == 3)
		ft_quick_three(lst_a, lst_b);
	else if (ft_lstsize((*lst_a)) == 4)
		ft_quick_four(lst_a, lst_b);
	else if (ft_lstsize(*lst_a) == 5)
		ft_quick_five(lst_a, lst_b);
	else
	{
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
}

int	ft_all_pivot(t_list *lst)
{
	if (!(lst))
		return (1);
	while (lst)
	{
		if (lst->pivot == 0)
			return (1);
		lst = lst->next;
	}
	return (0);
}

void	ft_check_pivot(t_list **lst)
{
	if ((*lst)->pivot == 0 && ft_lstlast((*lst))->pivot == 1
		&& (*lst)->next->pivot == 1)
		(*lst)->pivot = 1;
	(*lst) = (*lst)->next;
	while ((*lst)->next)
	{
		if ((*lst)->prev)
		{
			if ((*lst)->pivot == 0 && (*lst)->next->pivot == 1
				&& (*lst)->prev->pivot == 1)
				(*lst)->pivot = 1;
		}
		(*lst) = (*lst)->next;
	}
	if ((*lst)->pivot == 0 && ft_lstfront((*lst))->pivot == 1
		&& (*lst)->prev->pivot == 1)
		(*lst)->pivot = 1;
	(*lst) = ft_lstfront((*lst));
}

void	ft_check_two_element(t_list **lst)
{
	if (ft_lstsize((*lst)) >= 4)
	{
		if ((*lst)->pivot == 0 && ft_lstlast((*lst))->pivot == 1
			&& (*lst)->next->pivot == 0 && (*lst)->next->next->pivot == 1)
		{
			if ((*lst)->content < (*lst)->next->content)
				ft_sa_sb(lst, SB);
			(*lst)->pivot = 1;
			(*lst)->next->pivot = 1;
		}
	}
}

void	ft_new_element(t_list **lst_a, t_list **lst_b)
{
	while ((*lst_b)->pivot == 1)
	{
		ft_ra_rb(lst_b, RB);
		if ((*lst_b)->pivot == 0)
			ft_check_two_element(lst_b);
		if (!(ft_all_pivot((*lst_b))))
			break;
	}
	while ((*lst_b)->pivot == 0)
		ft_pa_pb(lst_a, lst_b, PA);
}
