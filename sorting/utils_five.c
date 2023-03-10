/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_five.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:17:46 by apaghera          #+#    #+#             */
/*   Updated: 2023/03/10 16:16:31 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>

/* void	find_lowest_num(t_data *data)
{
	t_node	*check;
	t_node	*node;
	t_node	*tmp;

	check = data->a->front;
	tmp = check;
	while (check)
	{
		node = check->next;
		while (node)
		{
			if (tmp->number > node->number)
				tmp = node;
			node = node->next;
		}
		check = check->next;
	}
	printf("%i\n", tmp->number);
}
 */

void	sorting_using_pb(t_data *data)
{
	if (data->a->front->index == 0)
		pb(data);
	if (data->a->front->next->next->index == 0)
	{
		ra(data);
		ra(data);
		pb(data);
	}
	if (data->a->front->next->next->next->index == 0)
	{
		rra(data);
		rra(data);
		pb(data);
	}
	if (data->a->front->next->index == 0)
	{
		ra(data);
		pb(data);
	}
	if (live_index(data->a, data->a->front) == 0)
	{
		pb(data);
		sort_three_numb(data);
		pa(data);
		pa(data);
	}
	if (live_index(data->a, data->a->rear) == 0)
	{
		rra(data);
		pb(data);
		sort_three_numb(data);
		pa(data);
		pa(data);
	}
	if (live_index(data->a, data->a->front->next) == 0)
	{
		ra(data);
		pb(data);
		sort_three_numb(data);
		pa(data);
		pa(data);
	}
	if (live_index(data->a, data->a->front->next->next) == 0)
	{
		rra(data);
		rra(data);
		pb(data);
		sort_three_numb(data);
		pa(data);
		pa(data);
	}
}
