/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:13:20 by apaghera          #+#    #+#             */
/*   Updated: 2023/04/02 20:01:59 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	message_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	index_stack(t_data *data)
{
	t_node	*current;
	t_node	*tmp;

	current = data->a->front;
	while (current)
	{
		tmp = data->a->front;
		while (tmp)
		{
			if (current->number > tmp->number)
				current->index++;
			tmp = tmp->next;
		}
		current = current->next;
	}
}

int	live_index(t_stack *stack, t_node *current)
{
	t_node	*tmp;
	int		index;

	index = 0;
	tmp = stack->front;
	while (tmp)
	{
		if (current->number > tmp->number)
			index++;
		tmp = tmp->next;
	}
	return (index);
}

int	high_idx_zero(t_node *current, int size)
{
	while (current)
	{
		if (current->index == 0)
			return (size);
		size++;
		current = current->next;
	}
	if (size == 0)
		return (0);
	else
		return (size);
}

void	babysit_index_0(t_data *data)
{
	t_node		*current;
	long int	size;

	current = data->a->front;
	size = 0;
	size = high_idx_zero(current, size);
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
