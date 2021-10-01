/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 15:51:34 by lbastian          #+#    #+#             */
/*   Updated: 2021/09/22 15:51:56 by lbastian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUICKSORT_H
# define QUICKSORT_H

void	ft_send_a_to_b(t_list **lst_a, t_list **lst_b);
int		ft_all_pivot(t_list *lst);
void	ft_check_pivot(t_list **lst);
void	ft_new_element(t_list **lst_a, t_list **lst_b);
int		ft_calc_mediane(t_list *lst);
void	ft_quick_three(t_list **lst_a, t_list **lst_b);
void	ft_quick_four(t_list **lst_a, t_list **lst_b);
void	ft_quick_five(t_list **lst_a, t_list **lst_b);
void	ft_quick_magic(t_list **lst_a, t_list **lst_b);

#endif
