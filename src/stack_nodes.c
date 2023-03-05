/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_nodes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:58:34 by apaghera          #+#    #+#             */
/*   Updated: 2023/03/05 18:20:48 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>

t_node	*new_node(int number)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->number = number;
	node->index = 0;
	node->position = 0;
	node->next = NULL;
	return (node);
}

t_stack	*create_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->front = NULL;
	stack->rear = NULL;
	stack->size = 0;
	return (stack);
}

void	add_node(t_stack *stack, int number)
{
	t_node	*node;

	node = new_node(number);
	if (!node)
		return ;
	if (stack->size == 0)
	{
		stack->front = node;
		stack->rear = node;
	}
	else
	{
		stack->rear->next = node;
		stack->rear = stack->rear->next;
	}
	stack->size++;
}

void	print_stack(t_stack *stack)
{
	t_node	*node;

	node = stack->front;
	while (node)
	{
		printf("stack: %i\n", node->number);
		node = node->next;
	}
}
