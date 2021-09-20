/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Bastian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 16:06:31 by Bastian           #+#    #+#             */
/*   Updated: 2021/09/20 15:03:36 by Bastian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lst.h"
#include "../includes/tools.h"
#include "../includes/operations.h"
#include "../includes/sort_ffs.h"
#include "../includes/tools.h"

#define SA "sa\n"
#define SB "sb\n"
#define PA "pa\n"
#define PB "pb\n"
#define RA "ra\n"
#define RB "rb\n"
#define RRA "rra\n"
#define RRB "rrb\n"

void	print_list(t_list *list)
{
	if (list != NULL)
	{
		while (list)
		{
			printf("%d ", list->content);
			printf("%d", list->pivot);
			printf("\n");
			list = list->next;
		}
	}
	printf("\n");
}

void	print_list_r(t_list *list)
{
	if (list == NULL)
		exit(EXIT_FAILURE);
	while (list)
	{
		printf("%d ", list->content);
		list = list->prev;
	}
	printf("\n");
}

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

void ft_send_a_to_b(t_list **lst_a, t_list **lst_b)
{
	int pivot;

	if (ft_lstsize((*lst_a)) == 3)
	{
		(*lst_a)->pivot = 1;
		(*lst_a)->next->pivot = 1;
		(*lst_a)->next->next->pivot = 1;
		ft_sort_three_a(lst_a);
		ft_pa_pb(lst_b, lst_a, PB);
		ft_pa_pb(lst_b, lst_a, PB);
		ft_pa_pb(lst_b, lst_a, PB);
	}
	else
	{
		while ((*lst_a))
		{
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
	if ((*lst)->pivot == 0 && ft_lstlast((*lst))->pivot == 1 && (*lst)->next->pivot == 1)
		(*lst)->pivot = 1;
	(*lst) = (*lst)->next;
	while ((*lst)->next)
	{
		if ((*lst)->prev)
		{
			if ((*lst)->pivot == 0 && (*lst)->next->pivot == 1 && (*lst)->prev->pivot == 1)
				(*lst)->pivot = 1;
		}
		(*lst) = (*lst)->next;
	}
	if ((*lst)->pivot == 0 && ft_lstfront((*lst))->pivot == 1)	
		(*lst)->pivot = 1;
	(*lst) = ft_lstfront((*lst));
}

void	ft_new_element(t_list **lst_a, t_list **lst_b)
{
	while ((*lst_b)->pivot == 1)
		ft_ra_rb(lst_b, RB);

	if ((*lst_b)->next->pivot == 1)
		(*lst_b)->pivot = 1;
	else
	{
		while ((*lst_b)->pivot == 0)
			ft_pa_pb(lst_a, lst_b, PA);
	}
}

int main(int argc, char **argv)
{
	int i;
	t_list *lst_a;
	t_list *lst_b;

	lst_a = NULL;
	lst_b = NULL;
	i = 1;
	if (argc > 2)
	{
		while (i < argc )
		{
			if (ft_atoi(&lst_a, argv[i]))
			{
				write(2, "Error\n", ft_strlen("Error\n"));
				return (1);
			}
			if (ft_check_dup(lst_a))
			{
				write(2, "Error\n", ft_strlen("Error\n"));
				return (1);
			}
			i++;
		}
		if (ft_list_is_sort(lst_a))
			return (0);
		if (argc == 3)
			ft_sa_sb(&lst_a, SA);
		else if (argc == 4)
			ft_sort_three_a(&lst_a);
		else if (argc == 5)
			ft_sort_ffs(&lst_a, &lst_b, 4);
		else if (argc == 6)
			ft_sort_ffs(&lst_a, &lst_b, 5);
		else if (argc == 7)
			ft_sort_ffs(&lst_a, &lst_b, 6);
		else
		{
			ft_send_a_to_b(&lst_a, &lst_b);
			while (ft_all_pivot(lst_b))
			{
				ft_new_element(&lst_a, &lst_b);
				ft_send_a_to_b(&lst_a, &lst_b);
				ft_check_pivot(&lst_b);
			}
			while ((lst_b))
				ft_pa_pb(&lst_a, &lst_b, PA);
			ft_right_order(&lst_a);
		}
	}
}
