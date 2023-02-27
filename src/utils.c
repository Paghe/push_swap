/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:06:47 by apaghera          #+#    #+#             */
/*   Updated: 2023/02/25 17:46:50 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	destroy_stack(t_stack *stack)
{
	while (stack->front)
		remove_node(stack);
	stack->rear = NULL;
	free(stack);
}

void	remove_node(t_stack *stack)
{
	t_node	*top_node;

	if (stack->size == 0)
		return ;
	top_node = stack->front;
	stack->front = stack->front->next;
	stack->size--;
	free(top_node);
	top_node = NULL;
}

void	free_mem(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

size_t	ft_strl(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoingn(char *s, char *s2)
{
	char	*s3;
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (!s)
	{
		s = ft_calloc(sizeof(char), 1);
		s[0] = '\0';
	}
	s3 = ft_calloc(sizeof(char), ft_strl(s) + ft_strl(s2) + 3);
	if (!s3)
		return (NULL);
	while (s[++i])
		s3[i] = s[i];
	while (s2[j])
		s3[i++] = s2[j++];
	s3[i] = ' ';
	s3[i + 1] = '\0';
	free(s);
	return (s3);
}
