/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 16:25:24 by apaghera          #+#    #+#             */
/*   Updated: 2023/03/05 20:01:03 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>

t_node	*find_zero_idx(t_data *data)
{
	t_node				*tmp;
	int					position;

	tmp = data->a->front;
	position = 1;
	while (tmp && tmp->next)
	{
		tmp = tmp->next;
		position++;
		if (tmp->index == 0)
		{
			tmp->position = position;
			return (tmp);
		}	
	}
	tmp->position = -1;
	return (NULL);
}

void	test(t_data *data)
{
	t_node	*tmp;
	int		count;

	tmp = find_zero_idx(data);
	count = tmp->position;
	if (tmp->position > (int)data->a->size / 2)
	{
		while (count != (data->a->rear->index))
		{
			rra(data);
			count++;
		}	
	}
/* 	printf("Position: %i\n", tmp->position);
	printf("Half size: %zu\n", data->a->size / 2); */
	printf("Count: %i\n", count);
	printf("Index: %i\n", data->a->rear->index);
	print_stack(data->a);
}
