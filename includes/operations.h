#ifndef OPERATIONS_H
#define OPERATIONS_H

#include "lst.h"
#define SA "sa\n"
#define SB "sb\n"
#define PA "pa\n"
#define PB "pb\n"
#define RA "ra\n"
#define RB "rb\n"
#define RRA "rra\n"
#define RRB "rrb\n"


int ft_sa_sb(t_list **lst, char *str);
int ft_ss(t_list **lst_a, t_list **lst_b);
int	ft_pa_pb(t_list **lst_1, t_list **lst_2, char *str);
int ft_ra_rb(t_list **lst, char *str);
int ft_rr(t_list **lst_a, t_list **lst_b);
int ft_rra_rrb(t_list **lst, char *str);
int ft_rrr(t_list **lst_a, t_list **lst_b);

#endif
