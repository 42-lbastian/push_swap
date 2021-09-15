/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Bastian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 16:06:31 by Bastian           #+#    #+#             */
/*   Updated: 2021/09/10 15:49:47 by Bastian          ###   ########.fr       */
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
		if (argc == 4)
			ft_sort_three(&lst_a);
		print_list(lst_a);
	}
}
