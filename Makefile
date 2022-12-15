NAME = push_swap

BONUS = checker

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

LIBFT = ./libft

GNL = ./get_next_line/

LIBFT_AR = ./libft/libft.a

SR_PATH = ./src/

OB_PATH = ./obj/

INCLUDE = -I ./header/push_swap.h

SR =		ft_lstadd_front.c	\
				ft_lstnew.c				\
				main.c						\
				clean_lst.c				\
				utils.c						\
				utils2.c					\
				utils3.c					\
				operations.c			\
				operations2.c			\
				operations3.c			\
				find_last.c				\
				tst.c							\
				quick_sort.c			\

BONUS_SR =	checker.c 						\
						checker_utils.c				\
						utils.c								\
						utils2.c							\
						quick_sort.c					\
						ft_lstadd_front.c			\
						ft_lstnew.c						\
						checker_op.c					\
						checker_op2.c					\
						checker_op3.c					\
						find_last.c						\
						clean_lst.c       		\
						get_next_line_utils.c	\
						get_next_line.c				\

BONUS_SRCS = $(addprefix ${SR_path}, ${BONUS_SR})

BONUS_OBJS = $(addprefix ${OB_PATH}, ${BONUS_SR:.c=.o})

GNL_SRCS = $(addprefix ${GNL}, ${GNL_SR})

GNL_OBJS = $(addprefix ${OB_PATH}, ${GNL_SR:.c=.o})

SRCS = $(addprefix ${SR_PATH}, ${SR})

OBJS = $(addprefix ${OB_PATH}, ${SR:.c=.o})

all:	${NAME}

$(OB_PATH)%.o : ${SR_PATH}%.c
			@mkdir -p ${OB_PATH}
			cc -c $< -o $@

${NAME}:	${OBJS}
			make -C ${LIBFT}
			cc -o ${NAME} ${INCLUDE} ${OBJS} ${LIBFT_AR}

bonus : ${BONUS}

${BONUS} : ${BONUS_OBJS}
			make -C ${LIBFT}
			cc  ${INCLUDE} ${BONUS_OBJS} ${LIBFT_AR} -o checker

clean:
		make clean -C ${LIBFT}
		${RM} ${OBJS}
		${RM} -r ${OB_PATH}

fclean: clean
		make fclean -C ${LIBFT}
		${RM} ${NAME}
		${RM} ${BONUS}

re:	fclean all

.PHONY: clean fclean re