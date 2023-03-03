/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 20:08:29 by apaghera          #+#    #+#             */
/*   Updated: 2023/03/03 18:37:46 by apaghera         ###   ########.fr       */
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
}

void	pa(t_data *data)
{
	push_to_from(data->a, data->b);
}

void	pb(t_data *data)
{
	push_to_from(data->b, data->a);
}
