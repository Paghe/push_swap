/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort_all.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 13:45:41 by apaghera          #+#    #+#             */
/*   Updated: 2023/03/09 19:20:18 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>

void	sort_zero_idx(t_data *data)
{
	t_node	*tmp;
	t_node	*tmp2;
	int		half_size;

	tmp = find_zero_idx(data);
	tmp2 = find_second_idx(data);
	half_size = (int)data->a->size / 2;
	if (tmp->position > half_size)
	{
		while (live_index(data, data->a->front) != 0)
			rra(data);
	}
	else
	{
		while (live_index(data, data->a->front) != 0)
			ra(data);
	}	
	if (live_index(data, data->a->front) == 0)
	{
		pb(data);
		tmp = find_zero_idx(data);
	}
}

