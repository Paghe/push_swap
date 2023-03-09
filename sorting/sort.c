/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 16:25:24 by apaghera          #+#    #+#             */
/*   Updated: 2023/03/09 19:46:34 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>

t_node	*find_zero_idx(t_data *data)
{
	t_node				*tmp;
	int					position;

	if (data->a->size == 0)
	{
		return (NULL);
	}	
	tmp = data->a->front;
	position = 1;
	while (tmp)
	{
		if (live_index(data, tmp) == 0)
		{
			tmp->position = position;
			return (tmp);
		}	
		tmp = tmp->next;
		position++;
	}
	return (NULL);
}

t_node	*find_second_idx(t_data *data)
{
	t_node				*tmp;
	int					position;

	if (data->a->size == 0)
		return (NULL);
	tmp = data->a->front;
	position = 1;
	while (tmp)
	{
		if (live_index(data, tmp) == 1)
		{
			tmp->position_two = position;
			return (tmp);
		}	
		tmp = tmp->next;
		position++;
	}
	return (NULL);
}

void	sorting_all(t_data *data)
{
	t_node	*tmp;
	t_node	*tmp2;
	int		near_end;

	tmp = find_zero_idx(data);
	tmp2 = find_second_idx(data);
	data->chunk = 0;
	while (data->a->size != 0)
	{
		if (data->chunk == 19)
		{
			printf("CHUNKS: %i\n", data->chunk);
			if (live_index(data, data->b->front) == 19)
			{
				data->chunk = 0;
			}
			if (live_index(data, data->b->front) != 19)
			{
				if (data->a->front->number > data->b->front->number)
				{
					while (live_index(data, data->b->front) != 0)
						rb(data);
					if (live_index(data, data->b->front) == 0)
						pb(data);
					data->chunk = 0;
				}
			}
		}
		if (data->a->size != 1)
			near_end = (int)data->a->size - tmp2->position_two;
		if (near_end > tmp->position && data->a->size > 1)
		{
			sort_zero_idx(data);
			data->chunk++;
			tmp2 = find_second_idx(data);
		}
		else
		{
			if (data->a->size != 1)
			{
				while (tmp2->position_two != (int)data->a->size + 1)
				{
					rra(data);
					tmp2->position_two++;
				}
				if (live_index(data, data->a->front) == 1)
				{
					pb(data);
					data->chunk++;
					tmp = find_zero_idx(data);
					tmp2 = find_second_idx(data);
					if (data->a->size > 1)
						near_end = (int)data->a->size - tmp2->position_two;
				}
			}
			if (data->a->size == 1)
			{
				pb(data);
				data->chunk++;
			}
		}
	}
	while ((int)data->b->size != 0)
	{
		pa(data);
	}	
/* 	print_stack(data->a); */
}
