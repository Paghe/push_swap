/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 22:45:36 by apaghera          #+#    #+#             */
/*   Updated: 2023/03/04 15:17:15 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>

static void	rotate_stack(t_stack *stack)
{
	t_node	*tmp;

	if (stack->size < 2)
		return ;
	tmp = stack->front;
	stack->front = stack->front->next;
	stack->rear->next = tmp;
	stack->rear = stack->rear->next;
	stack->rear->next = NULL;
}

void	ra(t_data *data)
{
	rotate_stack(data->a);
	printf("ra\n");
}

void	rb(t_data *data)
{
	rotate_stack(data->b);
	printf("rb\n");
}

void	rr(t_data *data)
{
	ra(data);
	rb(data);
}
