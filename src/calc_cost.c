/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_cost.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 14:21:03 by apaghera          #+#    #+#             */
/*   Updated: 2023/03/29 21:30:30 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>

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

void	cost_to_a(t_data *data, t_node	**node_b);

/* void	push_random_to_b(t_data *data)
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
			pb(data);
			count_push++;
		}
		else
			ra(data);
		count++;
	}
	while (stack_size - count_push > 3)
	{
		pb(data);
		count_push++;
	}
	sort_three_numb(data);
} */

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
			if (data->a->front->index == 0 || data->a->front->index == stack_size - 1)
			{
				ra(data);
				continue ;
			}
			pb(data);
			count_push++;
		}
		else
			ra(data);
		count++;
	}
	while (stack_size - count_push > 3)
	{
		if (data->a->front->index == 0 || data->a->front->index == stack_size - 1)
		{
			ra(data);
			continue ;
		}
		pb(data);
		count_push++;
	}
	sort_three_numb(data);
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

void	cost_to_a(t_data *data, t_node	**node_b)
{
	t_node	*tmp_a;
	int		cost;

	tmp_a = data->a->front;
	cost = 0;
	(*node_b)->yolo_a = 0;
	if ((*node_b)->index < tmp_a->index && (*node_b)->index > get_lost(tmp_a)->index)
	{
			cost = 0;
			return ;
	}
	while (tmp_a->next)
	{
		if (((*node_b)->index > tmp_a->index && (*node_b)->index < tmp_a->next->index))
		{
			cost++;
			if (cost > (int)data->a->size / 2)
			{
				cost = data->a->size - cost;
				cost *= -1;
			}
			(*node_b)->yolo_a = cost;
			return ;
		}
		cost++;
		tmp_a = tmp_a->next;
	}
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
	(*node_b)->yolo_a = cost;
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

void executioner(t_data *data, t_node *node)
{
	if (node->yolo_a > 0 && node->yolo_b > 0)
	{
		while (node->yolo_a > 0 && node->yolo_b > 0)
		{
			rr(data);
			node->yolo_a--;
			node->yolo_b--;
		}
	}
	if (node->yolo_a < 0 && node->yolo_b < 0)
	{
		while (node->yolo_a < 0 && node->yolo_b < 0)
		{
			rrr(data);
			node->yolo_a++;
			node->yolo_b++;
		}
	}
	while (node->yolo_a)
	{
		if (node->yolo_a > 0)
		{
			ra(data);
			node->yolo_a--;
		}
		else if (node->yolo_a < 0)
		{
			rra(data);
			node->yolo_a++;
		}
	}
	while (node->yolo_b != 0)
	{
		if (node->yolo_b > 0)
		{
			rb(data);
			node->yolo_b--;
		}
		else if (node->yolo_b < 0)
		{
			rrb(data);
			node->yolo_b++;
		}
	}
	pa(data);
}

void	babysit_index_0(t_data *data)
{
	t_node		*current;
	long int	size;

	current = data->a->front;
	size = 0;
	while (current)
	{
		if (current->index == 0)
		{
			break ;
		}
		size++;
		current = current->next;
	}
	if (size == 0)
		return ;
	current = data->a->front;
	if (size > (int)data->a->size / 2)
	{
		while (live_index(data->a, current) != 0)
		{
			rra(data);
			current = data->a->front;
		}
	}
	else
	{
		while (live_index(data->a, current) != 0)
		{
			ra(data);
			current = data->a->front;
		}
	}
}
