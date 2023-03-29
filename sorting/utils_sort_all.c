/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort_all.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 13:45:41 by apaghera          #+#    #+#             */
/*   Updated: 2023/03/22 20:51:04 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>

int	get_height(t_stack *stack, t_node *current)
{
	int		count;
	t_node	*tmp;

	if (stack->size == 0)
		return (-1);
	count = 1;
	tmp = stack->front;
	while (tmp)
	{
		if (tmp == current)
			return (count);
		count++;
		tmp = tmp->next;
	}
	return (-1);
}

t_node	*midpoint(t_stack *stack)
{
	t_node	*tmp;

	if (stack->size < 3)
		return (NULL);
	tmp = stack->front;
	while (tmp)
	{
		if (live_index(stack, tmp) == (stack->size / 2))
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}
