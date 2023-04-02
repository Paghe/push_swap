/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 11:19:17 by apaghera          #+#    #+#             */
/*   Updated: 2023/04/02 20:55:27 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_b(t_data data)
{
	push_random_to_b(&data);
	while (data.b->size != 0)
	{
		cost_mv_node(&data);
		executioner(&data, cheapest_mv(&data));
	}
	if (data.a->size != 3)
		babysit_index_0(&data);
}

int	main(int argc, char **argv)
{
	t_data			data;
	int				*cost;

	if (argc == 1)
		return (0);
	cost = (int *)malloc(sizeof(int) * 2);
	data = init_data(argc, argv);
	data.a = create_stack();
	data.b = create_stack();
	parsing(data);
	if (data.a->size <= 5)
		sort_five(&data);
	else
		sort_b(data);
	destroy_stack(data.a);
	destroy_stack(data.b);
	free(cost);
	return (0);
}
