FLAGS = -g -Wall -Wextra -Werror

NAME = push_swap

NAME_BONUS = checker

SRC = src/main.c \
		src/init_data.c	\
		src/stack_nodes.c \
		src/utils.c		\
		src/push_stack.c \
		src/swap_stack.c \
		src/rotate_stack.c \
		src/reverse_rotate_stack.c	\
		src/parse.c	\
		src/utils_parser.c	\
		src/utils_stack.c \
		src/utils_two.c	\
		sorting/sort_three.c \
		sorting/utils_sort.c \
		sorting/utils_sort_all.c \
		sorting/utils_sort_one.c \
		src/calc_cost.c \
		src/utils_calc.c \
		src/exec_move.c \
		sorting/sort_five.c

SRCB = check/checker.c \
		src/init_data.c	\
		src/stack_nodes.c \
		src/utils.c		\
		src/push_stack.c \
		src/swap_stack.c \
		src/rotate_stack.c \
		src/reverse_rotate_stack.c \
		src/parse.c	\
		src/utils_parser.c	\
		src/utils_stack.c \
		src/utils_two.c	\
		sorting/sort_three.c \
		sorting/utils_sort.c \
		sorting/utils_sort_all.c \
		sorting/utils_sort_one.c \
		check/get_next_line.c \
		check/get_next_line_utils.c \
		check/utils_checker.c \

OBJ = $(SRC:.c=.o)

OBJSB =  $(SRCB:.c=.o)

LIBFT = ./libft/libft.a

all: $(NAME)

%.o: %.c
	gcc $(FLAGS) -c $^ -o $@

$(NAME): $(OBJ) include/push_swap.h
	make -C libft
	gcc $(LINKFLAGS) $(OBJ) $(LIBFT) $(FLAGS) -o $(NAME)

clean:
	rm -f $(OBJ) $(OBJSB)
	make clean -C libft


bonus: $(OBJSB)
	make -C libft
	cc $(OBJSB) $(LIBFT) $(FLAGS) -o $(NAME_BONUS)

fclean:
	make clean
	rm -f $(NAME)
	rm -f $(NAME_BONUS)
	rm -f $(LIBFT)
re: fclean all