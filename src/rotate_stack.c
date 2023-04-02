/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 22:45:36 by apaghera          #+#    #+#             */
/*   Updated: 2023/04/02 19:38:47 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rotate_stack(t_stack *stack)
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
	ft_putstr_fd("ra\n", 1);
}

void	rb(t_data *data)
{
	rotate_stack(data->b);
	ft_putstr_fd("rb\n", 1);
}

void	rr(t_data *data)
{
	rotate_stack(data->a);
	rotate_stack(data->b);
	ft_putstr_fd("rr\n", 1);
}
