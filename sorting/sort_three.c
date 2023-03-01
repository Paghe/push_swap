/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:39:49 by apaghera          #+#    #+#             */
/*   Updated: 2023/03/01 20:33:05 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>

void	sort_three_numb(t_data *data)
{
	t_stack	*stack;

	stack = data->a;
	check_sort(data);
	sorting(data);
	printf("------------------------------\n");
	print_stack(data->a);
}
