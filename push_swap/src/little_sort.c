/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveil <aleveil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 12:29:10 by aleveil           #+#    #+#             */
/*   Updated: 2022/11/21 12:34:58 by aleveil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	little_sorting(t_node	**stack_a, t_node	**stack_b)
{
	int	stack_taille;

	if (stack_is_sorted(stack_a) || stack_size(*stack_a) == 0
		|| stack_size(*stack_a) == 1)
		return ;
	stack_taille = stack_size(*stack_a);
	if (stack_taille == 2)
		sa(stack_a);
	else if (stack_taille == 3)
		sort_three(stack_a);
	else if (stack_taille == 4)
		sort_four(stack_a);
	else if (stack_taille == 5)
		sort_five(stack_a, stack_b);
}

void	sort_three(t_node **stack_a)
{
	if (!stack_is_sorted(stack_a))
	{
		while (node_last(*stack_a)->index != 2)
			ra(stack_a);
		if (!stack_is_sorted(stack_a))
			sa(stack_a);
	}
}

void	sort_four(t_node **stack_a)
{
	if (!stack_is_sorted(stack_a))
	{
		while (node_last(*stack_a)->index != 3)
			ra(stack_a);
		if ((*stack_a)->index > (*stack_a)->next->index)
			sa(stack_a);
		if (!stack_is_sorted(stack_a))
			ra(stack_a);
		if ((*stack_a)->index > (*stack_a)->next->index)
			sa(stack_a);
		if (!stack_is_sorted(stack_a))
			rra(stack_a);
		if ((*stack_a)->index > (*stack_a)->next->index)
			sa(stack_a);
	}
}

void	sort_five(t_node	**stack_a, t_node	**stack_b)
{
	if (!stack_is_sorted(stack_a))
	{
		while (stack_size(*stack_a) > 2)
		{
			if ((*stack_a)->index < 3)
				pb(stack_a, stack_b);
			else
				ra(stack_a);
		}
		if ((*stack_a)->index > (*stack_a)->next->index)
			sa(stack_a);
		while ((*stack_b)->index != 2)
			rb(stack_b);
		pa(stack_b, stack_a);
		if ((*stack_b)->index < (*stack_b)->next->index)
			sb(stack_b);
		pa(stack_b, stack_a);
		pa(stack_b, stack_a);
	}
}
