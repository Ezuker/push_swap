SRC = \
	./srcs/push_swap.c \
	./srcs/push_swap_utils.c \
	./srcs/do_sa.c \
	./srcs/do_sb.c \
	./srcs/do_ss.c \
	./srcs/do_pb.c \
	./srcs/do_pa.c \
	./srcs/do_ra.c \
	./srcs/do_rb.c \
	./srcs/do_rr.c \
	./srcs/do_rra.c \
	./srcs/do_rrb.c \
	./srcs/do_rrr.c \
	./srcs/parsing.c \
	./srcs/debug.c \
	./srcs/set_targets.c \
	./srcs/sorts.c \
	./srcs/do_action_a.c \
	./srcs/do_action_b.c \
	./srcs/set_targets_utils.c \
	./srcs/get_total.c \

OBJ = ${SRC:.c=.o}
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -rf
NAME = push_swap
PRINTF = "./ft_printf"
LIBS	= libftprintf.a

all: ${NAME}

%.o: %.c
	$(CC) ${CFLAGS} -c $< -o $@

$(NAME): $(OBJ)
	make -C $(PRINTF)
	mv $(PRINTF)/libftprintf.a .
	$(CC) $(OBJ) $(LIBS) -o $(NAME)

clean:
	make clean -C $(PRINTF)
	${RM} ${OBJ}

fclean: clean
	make fclean -C $(PRINTF)
	${RM} ./libftprintf.a
	${RM} ${NAME}

re: fclean all

.PHONY : all clean fclean re
