/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:39:35 by apaghera          #+#    #+#             */
/*   Updated: 2023/04/02 19:38:15 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	check_sort(t_data *data)
{
	size_t	count;
	t_node	*node;

	count = 1;
	node = data->a->front;
	while (node && node->next)
	{
		if (node->number < node->next->number)
			count++;
		node = node->next;
	}
	if (count == data->a->size)
		exit(1);
}

void	mid_is_smaller(t_data *data)
{
	if (data->a->front->next->number < data->a->rear->number \
		&& data->a->front->next->number < data->a->front->number)
		sa(data);
}

void	mid_is_bigger(t_data *data)
{
	if (data->a->front->next->number > data->a->rear->number \
		&& data->a->front->next->number > data->a->front->number)
	{
		rra(data);
		if (data->a->front->number > data->a->front->next->number)
		{
			sa(data);
		}	
	}
}

void	front_rear_sort(t_data *data)
{
	if (data->a->front->next->number > data->a->rear->number \
		&& data->a->front->next->number < data->a->front->number)
	{
		sa(data);
		rra(data);
	}
}

void	sorting(t_data *data)
{
	if (data->a->size == 0)
		message_error();
	mid_is_smaller(data);
	mid_is_bigger(data);
	front_rear_sort(data);
}
