/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 17:19:52 by apaghera          #+#    #+#             */
/*   Updated: 2023/03/03 19:53:29 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>

void	parsing(t_data data)
{
	char	**split;
	char	*regroup;

	split = NULL;
	if (data.argc < 2)
		return ;
	if (data.argc > 1)
	{
		regroup = regroup_argv(data);
		split = ft_split(regroup, ' ');
	}
	check_correct_format(split);
	convert_in_numbers(data, split);
	check_sort(&data);
	index_stack(&data);
	print_stack(data.a);
	if (data.argc > 1)
		free_str_parse(regroup, split);
}
