/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 15:52:54 by lbastian          #+#    #+#             */
/*   Updated: 2021/09/22 15:52:55 by lbastian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H

int		ft_atoi(t_list **lst, char *str, long result, int neg_pos);
int		ft_strlen(char *str);
int		ft_list_is_sort(t_list *list);
void	ft_right_order(t_list **lst);
void	ft_give_index_numb(t_list **lst, int mark);
int		ft_little_index(t_list *lst);
void	ft_give_numb(t_list **lst, int mark);
int		ft_smaller_biggest_element(int nb, t_list *lst, int option);
int		ft_calc_mediane(t_list *lst);

#endif
