/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 11:19:17 by apaghera          #+#    #+#             */
/*   Updated: 2023/02/25 17:47:52 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "stdio.h"

int	main(int argc, char **argv)
{
	t_data	data;

	data = init_data(argc, argv);
	data.a = create_stack();
	data.b = create_stack();
	parsing(data);
	/* add_node(data.a, 1);
	add_node(data.a, 2);
	add_node(data.a, 3);
	add_node(data.b, 4); */
	destroy_stack(data.a);
	destroy_stack(data.b);
/* 	system("leaks push_swap"); */
	return (0);
}
