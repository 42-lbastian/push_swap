/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Bastian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 15:30:53 by Bastian           #+#    #+#             */
/*   Updated: 2021/09/20 15:32:20 by Bastian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/operations.h"
#include "../includes/lst.h"
#include "../includes/tools.h"

int	ft_rra_rrb(t_list **lst, char *str)
{
	int	value;
	int	pivot;

	if (!((*lst)->next))
		return (1);
	while ((*lst)->next)
		(*lst) = (*lst)->next;
	value = (*lst)->content;
	pivot = (*lst)->pivot;
	while ((*lst)->prev)
	{
		(*lst)->content = (*lst)->prev->content;
		(*lst)->pivot = (*lst)->prev->pivot;
		(*lst) = (*lst)->prev;
	}
	(*lst)->content = value;
	(*lst)->pivot = pivot;
	write(1, str, ft_strlen(str));
	return (0);
}

int	ft_rrr(t_list **lst_a, t_list **lst_b)
{
	if (ft_rra_rrb(lst_a, "") || ft_rra_rrb(lst_b, "rrr\n"))
		return (1);
	return (0);
}
