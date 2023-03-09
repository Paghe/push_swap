/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 11:19:17 by apaghera          #+#    #+#             */
/*   Updated: 2023/03/09 14:50:33 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "stdio.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 1)
		exit(1);
	data = init_data(argc, argv);
	data.a = create_stack();
	data.b = create_stack();
	parsing(data);
/* 	sort_five_num(&data); */
/* 	sorting_all(&data); */
	sorting_all(&data);
	destroy_stack(data.a);
	destroy_stack(data.b);
/* 	system("leaks push_swap"); */
	return (0);
}
