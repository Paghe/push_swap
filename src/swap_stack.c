/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 22:01:27 by apaghera          #+#    #+#             */
/*   Updated: 2023/04/02 19:37:16 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap_first_two(t_stack *stack)
{
	t_node	*tmp;
	t_node	*tmp2;

	if (stack->size < 2)
		return ;
	tmp2 = stack->front;
	tmp = stack->front->next;
	stack->front = stack->front->next->next;
	tmp->next = tmp2;
	tmp2->next = stack->front;
	stack->front = tmp;
}

void	sa(t_data *data)
{
	swap_first_two(data->a);
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_data *data)
{
	swap_first_two(data->b);
	ft_putstr_fd("sb\n", 1);
}

void	ss(t_data *data)
{
	swap_first_two(data->a);
	swap_first_two(data->b);
	ft_putstr_fd("ss\n", 1);
}
