/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 22:01:27 by apaghera          #+#    #+#             */
/*   Updated: 2023/02/24 14:10:05 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	swap_first_two(t_stack *stack)
{
	t_node	*tmp;

	if (stack->size < 2)
		return ;
	tmp = stack->front;
	stack->front = stack->front->next;
	stack->front->next = tmp;
}

void	sa(t_data *data)
{
	swap_first_two(data->a);
}

void	sb(t_data *data)
{
	swap_first_two(data->b);
}

void	ss(t_data *data)
{
	sa(data);
	sb(data);
}
