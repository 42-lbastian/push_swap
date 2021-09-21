/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Bastian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 16:06:31 by Bastian           #+#    #+#             */
/*   Updated: 2021/09/21 16:40:58 by Bastian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lst.h"
#include "../includes/tools.h"
#include "../includes/operations.h"
#include "../includes/sort_ffs.h"
#include "../includes/tools.h"
#include "../includes/quicksort.h"
#include "../includes/check.h"

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
			printf("%d ", list->index);
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
		ft_add_index(&lst_a);
		if (argc == 3)
			ft_sa_sb(&lst_a, SA);
		else if (argc == 4)
			ft_sort_three_a_main(&lst_a);
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
