/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Bastian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 15:16:46 by Bastian           #+#    #+#             */
/*   Updated: 2021/09/20 15:18:52 by Bastian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lst.h"
#include "../includes/check.h"

int	ft_check_numb(int val, t_list *lst)
{
	int i;

	i = 0;
	while (lst)
	{
		if (lst->content == val)
			i++;
		lst = lst->next;
	}
	if (i > 1)
		return (1);
	return (0);
}

int ft_check_dup(t_list *lst)
{
	while (lst)
	{
		if (ft_check_numb(lst->content, ft_lstfront(lst)))
			return (1);
		lst = lst->next;
	}
	return (0);
}
