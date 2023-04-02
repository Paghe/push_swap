/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 18:38:40 by apaghera          #+#    #+#             */
/*   Updated: 2023/04/02 19:19:08 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap_command(t_data *data, char *str)
{
	if (strcmp(str, "sa\n") == 0)
		swap_first_two(data->a);
	else if (strcmp(str, "sb\n") == 0)
		swap_first_two(data->b);
}

void	rotate_command(t_data *data, char *str)
{	
	if (strcmp(str, "ra\n") == 0)
		rotate_stack(data->a);
	else if (strcmp(str, "rb\n") == 0)
		rotate_stack(data->b);
}

void	reverse_command(t_data *data, char *str)
{
	if (strcmp(str, "rra\n") == 0)
		reverse_rotate_stack(data->a);
	else if (strcmp(str, "rrb\n") == 0)
		reverse_rotate_stack(data->b);
}

void	command_both_stack(t_data *data, char *str)
{
	if (strcmp(str, "rr\n") == 0)
	{
		rotate_stack(data->a);
		rotate_stack(data->b);
	}
	else if (strcmp(str, "rrr\n") == 0)
	{
		reverse_rotate_stack(data->a);
		reverse_rotate_stack(data->b);
	}
	else if (strcmp(str, "ss\n") == 0)
	{
		swap_first_two(data->a);
		swap_first_two(data->b);
		print_stack(data->a);
	}
	else if (strcmp(str, "pb\n") == 0)
		push_to_from(data->b, data->a);
	else if (strcmp(str, "pa\n") == 0)
		push_to_from(data->a, data->b);
}

void	do_command(t_data *data, char *str)
{
	swap_command(data, str);
	rotate_command(data, str);
	reverse_command(data, str);
	command_both_stack(data, str);
}
