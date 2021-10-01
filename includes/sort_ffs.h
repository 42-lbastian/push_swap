/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ffs.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 15:52:10 by lbastian          #+#    #+#             */
/*   Updated: 2021/09/22 15:52:32 by lbastian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_FFS_H
# define SORT_FFS_H

void	ft_sort_ffs(t_list **lst_a, t_list **lst_b, int nb);
void	ft_sort_three_a_main(t_list **lst);
void	ft_sort_three_b_main(t_list **lst);
int		ft_is_the_biggest(int nb, t_list *lst);

#endif
