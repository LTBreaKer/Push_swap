NAME = push_swap

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

LIBFT = ./libft

INCLUDE = -I ./header/push_swap.h

SRCS =	./src/ft_lstadd_front.c	\
				./src/ft_lstnew.c				\
				./src/main.c						\
				./src/clean_lst.c				\
				./src/utils.c						\
				./src/operations.c			\
				./src/operations2.c			\
				./src/operations3.c			\
				./src/find_last.c				\
				./src/tst.c							\

OBJS = ${SRCS:.c=.o}

all:	${NAME}

${NAME}:	${OBJS} ${LIBFT}
			make -C ${LIBFT}
			cc -o ${NAME} ${INCLUDE} ${OBJS} ${LIBFT}/libft.a

clean:
		make clean -C ${LIBFT}
		${RM} ${OBJS}

fclean: clean
		make fclean -C ${LIBFT}
		${RM} ${NAME}

re:	fclean all

.PHONY: clean fclean re