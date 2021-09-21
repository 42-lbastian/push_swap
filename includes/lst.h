#ifndef LST_H
#define LST_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct s_list
{
	int content;
	int pivot;
	int index;
	struct s_list *next;
	struct s_list *prev;
}				t_list;

t_list *ft_lstnew(int content, int pivot, int index);
int ft_lstsize(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list *ft_lstlast(t_list *lst);
t_list *ft_lstfront(t_list *lst);
void ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstdelone(t_list **lst);
void	ft_lstclear(t_list **lst);
void	ft_add_index(t_list **lst);

void	print_list(t_list *list);

#endif
