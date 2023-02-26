/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveil <aleveil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 10:20:18 by aleveil           #+#    #+#             */
/*   Updated: 2022/11/21 13:55:23 by aleveil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static	t_node	*get_min(t_node **stack)
{
	t_node	*current;
	t_node	*result;
	int		min;

	min = INT_MAX;
	result = NULL;
	current = *stack;
	while (current)
	{
		if (current->index == -1)
		{
			if (current->value <= min)
			{
				min = current->value;
				result = current;
			}
		}
		current = current->next;
	}
	return (result);
}

static int	all_got_index(t_node **stack)
{
	t_node	*current;

	current = *stack;
	while (current)
	{
		if (current->index == -1)
			return (0);
		current = current->next;
	}
	return (1);
}

void	put_index(t_node	**stack)
{
	t_node	*current;
	int		index;

	index = 0;
	while (!all_got_index(stack))
	{
		current = get_min(stack);
		if (!current)
			return ;
		current->index = index;
		index++;
	}
}
