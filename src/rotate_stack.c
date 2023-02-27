/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 22:45:36 by apaghera          #+#    #+#             */
/*   Updated: 2023/02/24 19:16:30 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	rotate_stack(t_stack *stack)
{
	t_node	*tmp;

	if (stack->size < 2)
		return ;
	tmp = stack->front;
	stack->front = stack->front->next;
	stack->rear->next = tmp;
	stack->rear = stack->rear->next;
}

void	ra(t_data *data)
{
	rotate_stack(data->a);
}

void	rb(t_data *data)
{
	rotate_stack(data->b);
}

void	rr(t_data *data)
{
	ra(data);
	rb(data);
}