/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 14:28:18 by apaghera          #+#    #+#             */
/*   Updated: 2023/04/02 19:37:28 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

char	*regroup_argv(t_data data)
{
	char	*regroup;
	int		i;

	regroup = ft_strdup("");
	i = 1;
	while (i < data.argc)
	{
		regroup = ft_strjoinpush(regroup, data.argv[i]);
		i++;
	}
	return (regroup);
}

void	check_correct_format(char **split)
{
	int	k;
	int	j;

	k = 0;
	while (split && split[k])
	{
		j = 0;
		if (!split[k][j] && j == 0)
			message_error();
		if ((split[k][j] == '-' || split[k][j] == '+') && j == 0)
			j++;
		while (split[k][j])
		{
			if (!ft_isdigit(split[k][j]) && split[k][j] != ' ')
				message_error();
			j++;
		}
		k++;
	}
}

void	convert_in_numbers(t_data data, char **split)
{
	int	i;

	i = 0;
	while (split && split[i])
	{
		check_stack_limits(split[i]);
		add_node(data.a, ft_push_atoi(split[i]));
		i++;
	}
	if (check_double_numbers(data.a) == 1)
		message_error();
}

void	free_str_parse(char *regroup, char **split)
{
	free(regroup);
	free_mem(split);
}
