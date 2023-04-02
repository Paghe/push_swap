/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 18:23:26 by apaghera          #+#    #+#             */
/*   Updated: 2023/04/02 19:37:39 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	checker_sort(t_data *data)
{
	size_t	count;
	t_node	*node;

	count = 1;
	node = data->a->front;
	while (node && node->next)
	{
		if (node->number < node->next->number)
			count++;
		node = node->next;
	}
	if (count == data->a->size)
		return (1);
	else
		return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;
	char	*str;

	if (argc == 1)
		return (0);
	data = init_data(argc, argv);
	data.a = create_stack();
	data.b = create_stack();
	parsing(data);
	str = get_next_line(0);
	while (str)
	{
		do_command(&data, str);
		free(str);
		str = get_next_line(0);
	}
	if (checker_sort(&data) && data.b->size == 0)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	destroy_stack(data.a);
	destroy_stack(data.b);
	return (0);
}
