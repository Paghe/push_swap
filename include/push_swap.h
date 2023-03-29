/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 11:20:01 by apaghera          #+#    #+#             */
/*   Updated: 2023/03/28 20:46:12 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include <limits.h>

typedef struct s_node		t_node;
typedef struct s_chunk		t_chunk;
typedef struct s_node
{
	int					number;
	int					index;
	int					position;
	int					position_two;
	int					yolo_a;
	int					yolo_b;
	t_node				*next;
}	t_node;

typedef struct s_chunk
{
	t_node		*start;
	t_node		*end;
	int			index;
	t_chunk		*next;
	int			size_chunk;
}	t_chunk;

typedef struct s_lst_chunks
{
	t_chunk	*first;
	t_chunk	*last;
	size_t	n_chunks;
}			t_lst_chunks;

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
	t_chunk				*chunk;
	t_lst_chunks		*lchunk;
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
char				*ft_strjoingn(char *s, char *s2);
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
void				sort_five_num(t_data *data);
int					find_lowest_num(t_data *data);
void				index_stack(t_data *data);
int					live_index(t_stack *stack, t_node *current);
void				sorting_using_pb(t_data *data);
void				sorting_all(t_data *data);
int					get_height(t_stack *stack, t_node *current);
void				sorting_one_hundred(t_data *data);
t_node				*midpoint(t_stack *stack);
void				test(t_data *data);
int					sort_first_mid(t_data *data);
t_chunk				*create_chunk(void);
void				add_node_chunk(t_chunk *chunk, int number);
void				add_chunk(t_lst_chunks *l_chunk, t_chunk *chunk);
void				destroy_chunk(t_chunk *chunk);
void				destroy_all_chunks(t_lst_chunks *lchunk);
t_node				*new_node_chunk(int number);
t_lst_chunks		*init_lst_chunk(void);
void				remove_node_chunk(t_chunk *chunk);
void				print_all_chunks(t_chunk *chunk);
int					find_bigest_num(t_data *data, int index);
int					live_index_chunk(t_chunk *chunk, t_node *current);
t_node				*midpoint_chunk(t_lst_chunks *lchunks, \
									t_chunk	*current_chunk, int index);
void				index_chunk(t_lst_chunks *lchunk);
t_chunk				*refresh_chunk(t_data *data, t_chunk *current_chunk, \
									int index);
int					check_chunk_sort(t_stack *stack);

void				push_random_to_b(t_data *data);
void				cost_mv_node(t_data *data);
t_node				*cheapest_mv(t_data *data);
void				executioner(t_data *data, t_node *node);
void				babysit_index_0(t_data *data);
#endif