/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort_one.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:17:46 by apaghera          #+#    #+#             */
/*   Updated: 2023/04/02 19:38:08 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	find_lowest_num(t_data *data)
{
	t_node	*check;
	t_node	*node;
	t_node	*tmp;
	int		min;

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
	min = tmp->index;
	return (min);
}
