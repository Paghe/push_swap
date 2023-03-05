/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 22:01:27 by apaghera          #+#    #+#             */
/*   Updated: 2023/03/04 15:12:45 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>

static void	swap_first_two(t_stack *stack)
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
	printf("sa\n");
}

void	sb(t_data *data)
{
	swap_first_two(data->b);
	printf("sb\n");
}

void	ss(t_data *data)
{
	sa(data);
	sb(data);
}
