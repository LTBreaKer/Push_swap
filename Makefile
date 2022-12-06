NAME = push_swap

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

LIBFT = ./libft

LIBFT_AR = ./libft/libft.a

SR_PATH = ./src/

OB_PATH = ./obj/

INCLUDE = -I ./header/push_swap.h

SR =		ft_lstadd_front.c	\
				ft_lstnew.c				\
				main.c						\
				clean_lst.c				\
				utils.c						\
				operations.c			\
				operations2.c			\
				operations3.c			\
				find_last.c				\
				tst.c							\

SRCS = $(addprefix ${SR_PATH}, ${SR})

OBJS = $(addprefix ${OB_PATH}, ${SR:.c=.o})

all:	${NAME}

$(OB_PATH)%.o : ${SR_PATH}%.c
			@mkdir -p ${dir ${OB_PATH}}
			cc -c $< -o $@

${NAME}:	${OBJS}
			make -C ${LIBFT}
			cc -o ${NAME} ${INCLUDE} ${OBJS} ${LIBFT_AR}

clean:
		make clean -C ${LIBFT}
		${RM} ${OBJS}

fclean: clean
		make fclean -C ${LIBFT}
		${RM} ${NAME}

re:	fclean all

.PHONY: clean fclean re