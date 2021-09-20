NAME = push_swap

SRCS = srcs/lst_1.c srcs/lst_2.c srcs/operations_1.c srcs/operations_2.c srcs/push_swap.c srcs/tools.c srcs/sort_ffs_1.c srcs/sort_ffs_2.c srcs/sort_ffs_3.c srcs/quicksort.c srcs/check.c

OBJS = ${SRCS:.c=.o}

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

all:	$(NAME)

$(NAME): ${OBJS}
	$(CC) -o $(NAME) $(CFLAGS) ${OBJS}

clean:
	${RM} ${OBJS} ${OBJS_BONUS}

fclean:	clean
		${RM} ${NAME}

re:		fclean all

.PHONY:	all clean fclean re bonus
