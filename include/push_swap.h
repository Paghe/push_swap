/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 11:20:01 by apaghera          #+#    #+#             */
/*   Updated: 2023/04/02 20:51:25 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include <limits.h>
# include "../check/get_next_line.h"

typedef struct s_node		t_node;
typedef struct s_node
{
	int					number;
	int					index;
	int					yolo_a;
	int					yolo_b;
	t_node				*next;
}	t_node;

typedef struct s_stack
{
	t_node		*front;
	t_node		*rear;
	size_t		size;
}				t_stack;

typedef struct s_data
{
	int					argc;
	char				**argv;
	t_stack				*a;
	t_stack				*b;
}	t_data;

t_data				init_data(int argc, char **argv);
t_node				*new_node(int number);
t_stack				*create_stack(void);
void				add_node(t_stack *stack, int number);
void				remove_node(t_stack *stack);
void				destroy_stack(t_stack *stack);
void				sa(t_data *data);
void				sb(t_data *data);
void				ss(t_data *data);
void				pa(t_data *data);
void				pb(t_data *data);
void				ra(t_data *data);
void				rb(t_data *data);
void				rr(t_data *data);
void				rra(t_data *data);
void				rrb(t_data *data);
void				rrr(t_data *data);
void				parsing(t_data data);
void				free_mem(char **str);
size_t				ft_strl(char *s);
char				*ft_strjoinpush(char *s, char *s2);
void				print_stack(t_stack *stack);
char				*regroup_argv(t_data data);
void				check_correct_format(char **split);
void				convert_in_numbers(t_data data, char **split);
void				free_str_parse(char *regroup, char **split);
int					check_double_numbers(t_stack *stack);
void				check_stack_limits(char *str);
long long			ft_push_atoi(const char *str);
void				message_error(void);
void				sort_three_numb(t_data *data);
void				check_sort(t_data *data);
void				mid_is_smaller(t_data *data);
void				mid_is_bigger(t_data *data);
void				sorting(t_data *data);
int					find_lowest_num(t_data *data);
void				index_stack(t_data *data);
int					live_index(t_stack *stack, t_node *current);
int					get_height(t_stack *stack, t_node *current);
void				push_random_to_b(t_data *data);
void				cost_mv_node(t_data *data);
t_node				*cheapest_mv(t_data *data);
void				executioner(t_data *data, t_node *node);
void				babysit_index_0(t_data *data);
t_node				*get_lost(t_node *node);
int					let_small_big(t_data *data, int stack_size);
void				push_rest(t_data *data, int stack_size, int count_push);
int					skip_gap(t_data *data, t_node *tmp_a, int cost);
int					calc_cost_between(t_data *data, t_node **node_b, \
										t_node *tmp_a, int cost);
void				swap_first_two(t_stack *stack);
void				rotate_stack(t_stack *stack);
void				reverse_rotate_stack(t_stack *stack);
void				do_command(t_data *data, char *str);
void				push_to_from(t_stack *to, t_stack *from);
int					high_idx_zero(t_node *current, int size);
void				sort_five(t_data *data);
#endif