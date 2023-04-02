/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:55:09 by apaghera          #+#    #+#             */
/*   Updated: 2023/03/31 18:03:29 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	best_rr(t_data *data, t_node *node)
{
	if (node->yolo_a > 0 && node->yolo_b > 0)
	{
		while (node->yolo_a > 0 && node->yolo_b > 0)
		{
			rr(data);
			node->yolo_a--;
			node->yolo_b--;
		}
	}
}

void	best_rrr(t_data *data, t_node *node)
{
	if (node->yolo_a < 0 && node->yolo_b < 0)
	{
		while (node->yolo_a < 0 && node->yolo_b < 0)
		{
			rrr(data);
			node->yolo_a++;
			node->yolo_b++;
		}
	}
}

void	rotate_stack_a(t_data *data, t_node *node)
{
	while (node->yolo_a)
	{
		if (node->yolo_a > 0)
		{
			ra(data);
			node->yolo_a--;
		}
		else if (node->yolo_a < 0)
		{
			rra(data);
			node->yolo_a++;
		}
	}
}

void	rotate_stack_b(t_data *data, t_node *node)
{
	while (node->yolo_b != 0)
	{
		if (node->yolo_b > 0)
		{
			rb(data);
			node->yolo_b--;
		}
		else if (node->yolo_b < 0)
		{
			rrb(data);
			node->yolo_b++;
		}
	}
}

void	executioner(t_data *data, t_node *node)
{
	best_rr(data, node);
	best_rrr(data, node);
	rotate_stack_a(data, node);
	rotate_stack_b(data, node);
	pa(data);
}
