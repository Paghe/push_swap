FLAGS = #-fsanitize=address -g -Wall -Wextra -Werror

NAME = push_swap

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
		sorting/sort_five.c \
		sorting/utils_five.c \
		sorting/utils_sort_all.c \
		src/calc_cost.c 	\

OBJ = $(SRC:.c=.o)

LIBFT = ./libft/libft.a

all: $(NAME)

%.o: %.c
	gcc $(FLAGS) -c $^ -o $@

$(NAME): $(OBJ) include/push_swap.h
	make -C libft
	gcc $(LINKFLAGS) $(OBJ) $(LIBFT) $(FLAGS) -o $(NAME)

clean:
	rm -f $(OBJ)
	make clean -C libft

fclean:
	make clean
	rm -f $(NAME)

re: fclean all