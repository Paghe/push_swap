/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_stack.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:13:38 by apaghera          #+#    #+#             */
/*   Updated: 2023/02/24 19:17:51 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	reverse_rotate_stack(t_stack *stack)
{
	t_node	*tmp;
	t_node	*new_last;

	if (stack->size < 2)
		return ;
	new_last = stack->front;
	tmp = stack->rear;
	while (new_last -> next ->next != NULL)
		new_last = new_last->next;
	new_last->next = NULL;
	tmp->next = stack->front;
	stack->front = tmp;
	stack->rear = new_last;
}

void	rra(t_data *data)
{
	reverse_rotate_stack(data->a);
}

void	rrb(t_data *data)
{
	reverse_rotate_stack(data->b);
}

void	rrr(t_data *data)
{
	rra(data);
	rrb(data);
}
