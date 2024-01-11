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

BONUS = \
	./bonus/srcs/push_swap_bonus.c \
	./bonus/srcs/push_swap_utils_bonus.c \
	./bonus/srcs/do_sa_bonus.c \
	./bonus/srcs/do_sb_bonus.c \
	./bonus/srcs/do_ss_bonus.c \
	./bonus/srcs/do_pb_bonus.c \
	./bonus/srcs/do_pa_bonus.c \
	./bonus/srcs/do_ra_bonus.c \
	./bonus/srcs/do_rb_bonus.c \
	./bonus/srcs/do_rr_bonus.c \
	./bonus/srcs/do_rra_bonus.c \
	./bonus/srcs/do_rrb_bonus.c \
	./bonus/srcs/do_rrr_bonus.c \
	./bonus/srcs/parsing_bonus.c \
	./bonus/srcs/debug_bonus.c \
	./bonus/srcs/get_next_line_bonus.c \
	./bonus/srcs/action_bonus.c \

OBJ = ${SRC:.c=.o}
BOBJ = ${BONUS:.c=.o}
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -rf
NAME = push_swap
NAME_BONUS = checker
PRINTF = "./ft_printf"
LIBS	= libftprintf.a

all: ${NAME}

%.o: %.c
	$(CC) ${CFLAGS} -c $< -o $@

$(NAME): $(OBJ)
	make -C $(PRINTF)
	mv $(PRINTF)/libftprintf.a .
	$(CC) $(OBJ) $(LIBS) -o $(NAME)

bonus:	$(BOBJ)
	make -C $(PRINTF)
	mv $(PRINTF)/libftprintf.a .
	$(CC) $(BOBJ) $(LIBS) -o $(NAME_BONUS)

clean:
	make clean -C $(PRINTF)
	${RM} ${OBJ} $(BOBJ)

fclean: clean
	make fclean -C $(PRINTF)
	${RM} ./libftprintf.a
	${RM} ./bonus/libftprintf.a
	${RM} ${NAME}
	${RM} $(NAME_BONUS)

re: fclean all



.PHONY : all clean fclean re bonus
