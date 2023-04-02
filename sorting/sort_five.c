/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 20:48:47 by apaghera          #+#    #+#             */
/*   Updated: 2023/04/02 20:59:33 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_five(t_data *data)
{
	int	i;

	i = 0;
	while (data->a->size != 3)
	{
		i = high_idx_zero(data->a->front, 0);
		if (live_index(data->a, data->a->front) == 0)
		{
			pb(data);
		}
		else
		{
			if ((i > (int)data->a->size / 2))
				rra(data);
			else
				ra(data);
		}
	}
	if (data->a->size == 3)
		sort_three_numb(data);
	while (data->b->size != 0)
		pa(data);
}
