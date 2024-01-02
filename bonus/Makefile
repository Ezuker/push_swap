SRC = \
	./srcs/checker_bonus.c \
	./srcs/push_swap_utils_bonus.c \
	./srcs/do_sa_bonus.c \
	./srcs/do_sb_bonus.c \
	./srcs/do_ss_bonus.c \
	./srcs/do_pb_bonus.c \
	./srcs/do_pa_bonus.c \
	./srcs/do_ra_bonus.c \
	./srcs/do_rb_bonus.c \
	./srcs/do_rr_bonus.c \
	./srcs/do_rra_bonus.c \
	./srcs/do_rrb_bonus.c \
	./srcs/do_rrr_bonus.c \

OBJ = ${SRC:.c=.o}
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -rf
NAME = checker
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
