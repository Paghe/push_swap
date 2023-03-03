/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 17:49:45 by apaghera          #+#    #+#             */
/*   Updated: 2023/03/03 12:09:12 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	check_double_numbers(t_stack *stack)
{
	t_node	*node;
	t_node	*check;

	check = stack->front;
	while (check)
	{
		node = check->next;
		while (node)
		{
			if (check->number == node->number)
				return (1);
			node = node->next;
		}	
		check = check->next;
	}
	return (0);
}

void	check_stack_limits(char *str)
{
	if (ft_push_atoi(str) > INT_MAX || ft_push_atoi(str) < INT_MIN)
		message_error();
}

long long	ft_push_atoi(const char *str)
{
	int			sign;
	long long	res;

	sign = 1;
	res = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-')
		sign *= -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + *str - '0';
		str++;
	}
	return (res * sign);
}
