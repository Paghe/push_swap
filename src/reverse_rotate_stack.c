/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_stack.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:13:38 by apaghera          #+#    #+#             */
/*   Updated: 2023/04/02 19:35:18 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	reverse_rotate_stack(t_stack *stack)
{
	t_node	*tmp;
	t_node	*new_last;

	if (stack->size < 2)
		return ;
	new_last = stack->front;
	tmp = stack->rear;
	while (new_last->next->next != NULL)
		new_last = new_last->next;
	stack->rear = new_last;
	tmp->next = stack->front;
	stack->front = tmp;
	stack->rear->next = NULL;
}

void	rra(t_data *data)
{
	reverse_rotate_stack(data->a);
	ft_putstr_fd("rra\n", 1);
}

void	rrb(t_data *data)
{
	reverse_rotate_stack(data->b);
	ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_data *data)
{
	reverse_rotate_stack(data->a);
	reverse_rotate_stack(data->b);
	ft_putstr_fd("rrr\n", 1);
}
