/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:13:20 by apaghera          #+#    #+#             */
/*   Updated: 2023/03/03 17:04:42 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	message_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	index_stack(t_data *data)
{
	t_node	*current;
	t_node	*tmp;

	current = data->a->front;
	while (current)
	{
		tmp = data->a->front;
		while (tmp)
		{
			if (current->number > tmp->number)
				current->index++;
			tmp = tmp->next;
		}
		current = current->next;
	}
}

int	live_index(t_data *data, t_node *current)
{
	t_node	*tmp;
	int		index;

	index = 0;
	tmp = data->a->front;
	while (tmp)
	{
		if (current->number > tmp->number)
			index++;
		tmp = tmp->next;
	}
	return (index);
}
