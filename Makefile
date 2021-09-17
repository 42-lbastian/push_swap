NAME = push_swap

SRCS = srcs/lst_1.c srcs/operations.c srcs/push_swap.c srcs/tools.c

OBJS = ${SRCS:.c=.o}

CC = gcc

INCLUDES = includes/lst.h includes/tools.h includes/operations.h

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
