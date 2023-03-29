/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 11:19:17 by apaghera          #+#    #+#             */
/*   Updated: 2023/03/29 21:29:43 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "stdio.h"

int	main(int argc, char **argv)
{
	t_data			data;
	int				*cost;

	if (argc == 1)
		exit(1);
	cost = (int *)malloc(sizeof(int) * 2);
	data = init_data(argc, argv);
	data.a = create_stack();
	data.b = create_stack();
	parsing(data);
	push_random_to_b(&data);
	while (data.b->size != 0)
	{
		cost_mv_node(&data);
		executioner(&data, cheapest_mv(&data));
	}
/* 	while(data.a->front)
	{
		printf("INDEX: [%i]\t NUMBER [%i]\n", data.a->front->index, data.a->front->number);
		data.a->front = data.a->front->next;
	} */
	babysit_index_0(&data);
	// print_stack(data.a);
	// printf("--------------\n");
	// print_stack(data.b);
	destroy_stack(data.a);
	destroy_stack(data.b);
	free(cost);
	/* system("leaks push_swap"); */
	return (0);
}

	/* 	t_chunk			*chunk;
	t_chunk			*chunk2;
	t_node			*node; */
	/* add_chunk(lchunks, create_chunk());
	add_chunk(lchunks, create_chunk());
	lchunks->first->start = new_node_chunk(55);
	lchunks->first->next->start = new_node_chunk(35);
	add_chunk(lchunks, create_chunk());
	lchunks->first->next->start = new_node_chunk(25);
	data.lchunk = init_lst_chunk(); */
	// printf("%d", chunk->start->next->number_chunk);