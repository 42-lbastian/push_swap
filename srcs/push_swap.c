/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Bastian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 16:06:31 by Bastian           #+#    #+#             */
/*   Updated: 2021/09/17 10:37:31 by Bastian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lst.h"
#include "../includes/tools.h"
#include "../includes/operations.h"

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

int		ft_list_is_sort(t_list *list)
{
	while (list->next)
	{
		if (list->content > list->next->content)
			return (0);
		list = list->next;
	}
	return (1);
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

void	ft_right_order(t_list **lst)
{
	int i;
	int numb;
	int y;

	i = 0;
	y = 0;
	numb = (*lst)->content;
	while((*lst)->next)
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
	while (!(ft_list_is_sort((*lst))))
	{
		if (y < i / 2)
			ft_ra_rb(lst, RA);
		else
			ft_rra_rrb(lst, RRA);
	}
}

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

void	ft_sort_three(t_list **lst)
{
	if ((*lst)->content < (*lst)->next->content && (*lst)->next->content > (*lst)->next->next->content && (*lst)->content < (*lst)->next->next->content)
	{
		ft_sa_sb(lst, SA);
		ft_ra_rb(lst, RA);
	}
	if ((*lst)->content > (*lst)->next->content && (*lst)->next->content < (*lst)->next->next->content && (*lst)->content < (*lst)->next->next->content)
		ft_sa_sb(lst, SA);
	if ((*lst)->content < (*lst)->next->content && (*lst)->next->content > (*lst)->next->next->content && (*lst)->content > (*lst)->next->next->content)
		ft_rra_rrb(lst, RRA);
	if ((*lst)->content > (*lst)->next->content && (*lst)->next->content < (*lst)->next->next->content && (*lst)->content > (*lst)->next->next->content)
		ft_ra_rb(lst, RA);
	if ((*lst)->content > (*lst)->next->content && (*lst)->next->content > (*lst)->next->next->content && (*lst)->content > (*lst)->next->next->content)
	{
		ft_sa_sb(lst, SA);
		ft_rra_rrb(lst, RRA);
	}
}

void	ft_sort_ffs(t_list **lst_a, t_list **lst_b, int nb)
{
	ft_pa_pb(lst_b, lst_a, PB);
	if (nb > 4)
		ft_pa_pb(lst_b, lst_a, PB);
	if (nb > 5)
		ft_pa_pb(lst_b, lst_a, PB);
	if (!(ft_list_is_sort((*lst_a))))
		ft_sort_three(lst_a);
	if (!(ft_list_is_sort((*lst_b))))
	{
		if (nb == 5)
			ft_sa_sb(lst_b, SB);
		if (nb == 6)
			ft_sort_three(lst_a);
	}
	while ((*lst_b))
	{
		if (ft_is_the_biggest((*lst_b)->content, (*lst_a)))
		{
			ft_right_order(lst_a);
			ft_pa_pb(lst_a, lst_b, PA);
			ft_ra_rb(lst_a, RA);
			break ;
		}
		while ((*lst_a)->content < (*lst_b)->content)
				ft_ra_rb(lst_a, RA);
		ft_pa_pb(lst_a, lst_b, PA);
	}
	ft_right_order(lst_a);
	print_list((*lst_a));
	print_list((*lst_b));
}

void ft_send_a_to_b(t_list **lst_a, t_list **lst_b)
{
	int pivot;

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
		ft_pa_pb(lst_b, lst_a, PA);
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
	while ((*lst)->next)
	{
		if ((*lst)->pivot == 0 && (*lst)->next->pivot == 1)
			(*lst)->pivot = 1;
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
	int pivot;
	t_list *lst_a;	
	t_list *lst_b;	

	lst_a = NULL;
	lst_b = NULL;
	i = 1;
	if (argc > 1)
	{
		while (i < argc )
		{
			if (ft_atoi(&lst_a, argv[i]))
			{
						printf("Error\n");
				return (1);
			}
			if (ft_check_dup(lst_a))
			{
						printf("Error\n");
				return (1);
			}
			i++;
		}
		if (ft_list_is_sort(lst_a))
			return (0);
		print_list(lst_a);
		if (argc == 3)
			ft_sa_sb(&lst_a, SA);
		else if (argc == 4)
			ft_sort_three(&lst_a);
		else if (argc == 5)
			ft_sort_ffs(&lst_a, &lst_b, 4);
		else if (argc == 6)
			ft_sort_ffs(&lst_a, &lst_b, 5);
		else
		{
			ft_send_a_to_b(&lst_a, &lst_b);
			while (ft_all_pivot(lst_b))
			{
				ft_new_element(&lst_a, &lst_b);
				ft_send_a_to_b(&lst_a, &lst_b);
				ft_check_pivot(&lst_b);
				print_list(lst_a);
				print_list(lst_b);
			}
			while ((lst_b))
				ft_pa_pb(&lst_a, &lst_b, PA);
			while (!(ft_list_is_sort(lst_a)))
			{
				ft_ra_rb(&lst_a, RA);
			}
			print_list(lst_a);
		}
	}
}
