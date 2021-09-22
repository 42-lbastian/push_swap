/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_quicksort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 13:08:56 by lbastian          #+#    #+#             */
/*   Updated: 2021/09/22 14:03:16 by lbastian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lst.h"
#include "../includes/tools.h"
#include "../includes/operations.h"

int	ft_calc_mediane(t_list *lst)
{
	int	nb_big;
	int	nb_small;
	int	nb;

	nb = lst->content;
	while (lst)
	{
		nb_small = ft_smaller_biggest_element(lst->content,
				ft_lstfront(lst), 0);
		nb_big = ft_smaller_biggest_element(lst->content, ft_lstfront(lst), 1);
		if (nb_big == nb_small)
		{
			nb = lst->content;
			break ;
		}
		if (nb_small + 1 == nb_big)
		{
			nb = lst->content;
			break ;
		}
		lst = lst->next;
	}
	return (nb);
}

int	ft_smaller_biggest_element(int nb, t_list *lst, int option)
{
	int	big;
	int	small;

	big = 0;
	small = 0;
	while (lst)
	{
		if (lst->content > nb)
			big++;
		else if (lst->content < nb)
			small++;
		lst = lst->next;
	}
	if (option == 1)
		return (big);
	return (small);
}

int	ft_little_index(t_list *lst)
{
	int	nb;

	nb = lst->index;
	while ((lst))
	{
		if (lst->index < nb)
			nb = lst->index;
		lst = lst->next;
	}
	return (nb);
}

void	ft_give_numb(t_list **lst, int mark)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while ((*lst)->next)
	{
		if ((*lst)->content == mark)
			y = i;
		(*lst) = (*lst)->next;
		i++;
	}
	if ((*lst)->content == mark)
		y = i;
	(*lst) = ft_lstfront((*lst));
	while ((*lst)->content != mark)
	{
		if (y <= i / 2)
			ft_ra_rb(lst, RA);
		else
			ft_rra_rrb(lst, RRA);
	}
}

void	ft_give_index_numb(t_list **lst, int mark)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while ((*lst)->next)
	{
		if ((*lst)->index == mark)
			y = i;
		(*lst) = (*lst)->next;
		i++;
	}
	if ((*lst)->index == mark)
		y = i;
	(*lst) = ft_lstfront((*lst));
	while ((*lst)->index != mark)
	{
		if (y <= i / 2)
			ft_ra_rb(lst, RA);
		else
			ft_rra_rrb(lst, RRA);
	}
}
