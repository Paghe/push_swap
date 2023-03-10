/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 16:25:24 by apaghera          #+#    #+#             */
/*   Updated: 2023/03/10 18:01:45 by apaghera         ###   ########.fr       */
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
		if (live_index(data->a, tmp) == 0)
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
		if (live_index(data->a, tmp) == 1)
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
			printf("Front Number: %i\n", data->b->front->number);
			printf("Last Number B: %i\n", data->b->rear->number);
			print_stack(data->b);
			if (live_index(data->b, data->b->front) != 0)
			{
				while (live_index(data->b, data->b->front) != 0 && data->chunk != 0)
				{
					rb(data);
					data->chunk--;
				}	
			}
			if (live_index(data->b, data->b->front) == 0)
			{
				if (data->a->front->number > data->b->front->number)
				{
					pb(data);
				}	
				else
				{
					while (live_index(data->b, data->b->front) != 0)
					{	
						rb(data);
					}
				}
			}
			while (live_index(data->b, data->b->front) != 19)
			{
				rb(data);
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
				if (live_index(data->a, tmp2) == 1)
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
/* 	while (live_index(data->b, data->b->front) != 99)
	{
		rb(data);
	} */
	while ((int)data->b->size != 0)
	{
		pa(data);
	}	
/* 	print_stack(data->a); */
}
