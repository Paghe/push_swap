/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 20:08:29 by apaghera          #+#    #+#             */
/*   Updated: 2023/04/02 19:35:06 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push_to_from(t_stack *to, t_stack *from)
{
	t_node	*tmp;

	if (from->size == 0)
		return ;
	tmp = from->front;
	from->front = from->front->next;
	tmp->next = to->front;
	to->front = tmp;
	to->size++;
	from->size--;
	if (!to->rear)
		to->rear = tmp;
}

void	pa(t_data *data)
{
	push_to_from(data->a, data->b);
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_data *data)
{
	push_to_from(data->b, data->a);
	ft_putstr_fd("pb\n", 1);
}
