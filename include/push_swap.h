/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 11:20:01 by apaghera          #+#    #+#             */
/*   Updated: 2023/02/27 14:26:14 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include <limits.h>

typedef struct s_node	t_node;

typedef struct s_node
{
	int					number;
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

t_data		init_data(int argc, char **argv);
t_node		*new_node(int number);
t_stack		*create_stack(void);
void		add_node(t_stack *stack, int number);
void		remove_node(t_stack *stack);
void		destroy_stack(t_stack *stack);
void		sa(t_data *data);
void		sb(t_data *data);
void		ss(t_data *data);
void		pa(t_data *data);
void		pb(t_data *data);
void		ra(t_data *data);
void		rb(t_data *data);
void		rr(t_data *data);
void		rra(t_data *data);
void		rrb(t_data *data);
void		rrr(t_data *data);
void		parsing(t_data data);
void		free_mem(char **str);
size_t		ft_strl(char *s);
char		*ft_strjoingn(char *s, char *s2);
void		print_stack(t_stack *stack);
char		*regroup_argv(t_data data);
void		check_correct_format(char **split);
void		convert_in_numbers(t_data data, char **split);
void		free_str_parse(char *regroup, char **split);
int			check_double_numbers(t_stack *stack);
void		check_stack_limits(char *str);
long long	ft_push_atoi(const char *str);
void		message_error(void);
#endif