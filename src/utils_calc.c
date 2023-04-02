/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_calc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:29:23 by apaghera          #+#    #+#             */
/*   Updated: 2023/03/31 17:33:08 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_node	*get_lost(t_node *node)
{
	t_node	*current;

	current = node;
	while (current)
	{
		if (!current -> next)
			return (current);
		current = current -> next;
	}
	return (NULL);
}

int	let_small_big(t_data *data, int stack_size)
{
	if (data->a->front->index == 0 || data->a->front->index == stack_size - 1)
	{
		ra(data);
		return (1);
	}
	return (0);
}

void	push_rest(t_data *data, int stack_size, int count_push)
{
	while (stack_size - count_push > 3)
	{
		if (let_small_big(data, stack_size))
			continue ;
		pb(data);
		count_push++;
	}
	sort_three_numb(data);
}

int	skip_gap(t_data *data, t_node *tmp_a, int cost)
{
	if (tmp_a->next == NULL)
	{
		tmp_a = data->a->front;
		cost = 0;
		while (tmp_a->index != find_lowest_num(data))
		{
			cost++;
			tmp_a = tmp_a->next;
		}
	}
	return (cost);
}

int	calc_cost_between(t_data *data, t_node **node_b, t_node *tmp_a, int cost)
{
	while (tmp_a->next)
	{
		if (((*node_b)->index > tmp_a->index && \
				(*node_b)->index < tmp_a->next->index))
		{
			cost++;
			if (cost > (int)data->a->size / 2)
			{
				cost = data->a->size - cost;
				cost *= -1;
			}
			(*node_b)->yolo_a = cost;
			return (cost);
		}
		cost++;
		tmp_a = tmp_a->next;
	}
	return (cost);
}
