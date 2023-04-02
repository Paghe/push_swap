/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_cost.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 14:21:03 by apaghera          #+#    #+#             */
/*   Updated: 2023/04/02 19:38:25 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	cost_to_a(t_data *data, t_node	**node_b);

void	push_random_to_b(t_data *data)
{
	int	stack_size;
	int	count_push;
	int	count;

	stack_size = (int)data->a->size;
	count_push = 0;
	count = 0;
	while (stack_size > 6 && count < stack_size && count_push < stack_size / 2)
	{
		if (data->a->front->index <= stack_size / 2)
		{
			if (let_small_big(data, stack_size))
				continue ;
			pb(data);
			count_push++;
		}
		else
			ra(data);
		count++;
	}
	push_rest(data, stack_size, count_push);
}

void	cost_to_a(t_data *data, t_node	**node_b)
{
	t_node	*tmp_a;
	int		cost;

	tmp_a = data->a->front;
	cost = 0;
	(*node_b)->yolo_a = 0;
	if ((*node_b)->index < tmp_a->index && \
			(*node_b)->index > get_lost(tmp_a)->index)
	{
		cost = 0;
		return ;
	}
	cost = calc_cost_between(data, node_b, tmp_a, cost);
	if (tmp_a->next == NULL)
		cost = skip_gap(data, tmp_a, cost);
	(*node_b)->yolo_a = cost;
}

void	cost_mv_node(t_data *data)
{
	t_node	*tmp_b;
	int		size_stack;

	tmp_b = data->b->front;
	size_stack = 0;
	tmp_b->yolo_b = 0;
	while (tmp_b)
	{
		if (size_stack < (int)data->b->size / 2)
				tmp_b->yolo_b = size_stack;
		else
		{
			tmp_b->yolo_b = (data->b->size - size_stack);
			tmp_b->yolo_b *= -1;
		}
		cost_to_a(data, &tmp_b);
		size_stack++;
		tmp_b = tmp_b->next;
	}
}

int	abs_value(int n)
{
	if (n < 0)
		n *= -1;
	return (n);
}

t_node	*cheapest_mv(t_data *data)
{
	int		cheap;
	t_node	*current;
	t_node	*cheapest;

	current = data->b->front;
	cheap = INT_MAX;
	while (current)
	{
		if (cheap > abs_value(current->yolo_a) + abs_value(current->yolo_b))
		{
			cheap = abs_value(current->yolo_a) + abs_value(current->yolo_b);
			cheapest = current;
		}
		current = current->next;
	}
	return (cheapest);
}
