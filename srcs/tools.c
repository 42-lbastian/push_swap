/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Bastian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 10:56:14 by Bastian           #+#    #+#             */
/*   Updated: 2021/09/09 14:56:20 by Bastian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lst.h"

int ft_strlen(char *str)
{
	int compt;

	compt = 0;
	while (str[compt])
		compt++;
	return (compt);
}

int ft_atoi(t_list **lst, char *str)
{
	int neg_pos;
	long result;
	int index;
	long compt;

	result = 0;
	index = ft_strlen(str) - 1;
	compt = 1;
	neg_pos = 1;
	if (str[0] == '-')
		neg_pos = -1;
	while (index >= 0)
	{
		if (index == 0 && neg_pos == -1)
			break ;
		if (str[index] >= '0' && str[index] <= '9')
			result += compt * (str[index] - '0');
		else
			return (1);
		index--;
		compt *= 10;
	}
	result *= neg_pos;
	if (result > 2147483647 || result < -2147483648  || compt > 100000000000)
		return (1);
	ft_lstadd_back(lst, ft_lstnew((int)result, 0));
	return (0);
}
