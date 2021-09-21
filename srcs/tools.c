/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Bastian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 10:56:14 by Bastian           #+#    #+#             */
/*   Updated: 2021/09/21 16:01:51 by Bastian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lst.h"
#include "../includes/tools.h"
#include "../includes/operations.h"

int		ft_little_index(t_list *lst)
{
	int nb;
	
	nb = lst->index;
	while ((lst))
	{
		if (lst->index < nb)
			nb = lst->index;
		lst = lst->next;
	}
	return (nb);
}

void	ft_give_little_numb(t_list **lst, int mark)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while ((*lst)->next)
	{
		if ((*lst)->index == mark)
			y = i;
		i++;
		(*lst) = (*lst)->next;
	}
	(*lst) = ft_lstfront((*lst));
	while ((*lst)->index != mark)
	{
		if (y <= i / 2)
			ft_ra_rb(lst, RA);
		else
			ft_rra_rrb(lst, RRA);
	}
}

int	ft_list_is_sort(t_list *list)
{
	while (list->next)
	{
		if (list->content > list->next->content)
			return (0);
		list = list->next;
	}
	return (1);
}

void	ft_right_order_ra_rra(t_list **lst, int y, int i)
{
	while (!(ft_list_is_sort((*lst))))
	{
		if (y < i / 2)
			ft_ra_rb(lst, RA);
		else
			ft_rra_rrb(lst, RRA);
	}
}

void	ft_right_order(t_list **lst)
{
	int	i;
	int	numb;
	int	y;

	i = 0;
	y = 0;
	numb = (*lst)->content;
	while ((*lst)->next)
	{
		if ((*lst)->content < numb)
		{
			numb = (*lst)->content;
			y = i;
		}
		i++;
		(*lst) = (*lst)->next;
	}
	if ((*lst)->content < numb)
		y = i;
	(*lst) = ft_lstfront((*lst));
	ft_right_order_ra_rra(lst, y, i);
}

int	ft_strlen(char *str)
{
	int	compt;

	compt = 0;
	while (str[compt])
		compt++;
	return (compt);
}

int	ft_atoi(t_list **lst, char *str)
{
	int		neg_pos;
	long	result;
	int		index;
	long	compt;

	result = 0;
	index = ft_strlen(str) - 1;
	compt = 1;
	neg_pos = 1;
	if (str[0] == '-')
		neg_pos = -1;
	while (index >= 0)
	{
		if (index == 0 && (str[0] == '-' || str[0] == '+'))
			break ;
		if (str[index] >= '0' && str[index] <= '9')
			result += compt * (str[index] - '0');
		else
			return (1);
		index--;
		compt *= 10;
	}
	result *= neg_pos;
	if (result > 2147483647 || result < -2147483648 || compt > 100000000000)
		return (1);
	ft_lstadd_back(lst, ft_lstnew((int)result, 0, 0));
	return (0);
}
