/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveil <aleveil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 10:19:30 by aleveil           #+#    #+#             */
/*   Updated: 2022/11/21 13:58:41 by aleveil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	choose_sort(t_node	**stack_a, t_node	**stack_b)
{
	if (stack_size(*stack_a) <= 5)
		little_sorting(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b);
}

static void	free_stack(t_node	**stack)
{
	t_node	*head;
	t_node	*tmp;

	head = *stack;
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
	free(stack);
}

static void	free_both_stacks(t_node	**stack_a, t_node	**stack_b)
{
	free_stack(stack_a);
	free_stack(stack_b);
}

int	main(int argc, char **argv)
{
	t_node	**stack_a;
	t_node	**stack_b;

	if (argc < 2)
		return (0);
	if (!check_input(argc, argv))
		return (1);
	stack_a = (t_node **)malloc(sizeof(t_node *));
	stack_b = (t_node **)malloc(sizeof(t_node *));
	*stack_a = NULL;
	*stack_b = NULL;
	if (argc == 2)
		create_stack(ft_split(argv[1], ' '), argc, stack_a);
	else
		create_stack(argv, argc, stack_a);
	if (stack_is_sorted(stack_a))
	{
		free_both_stacks(stack_a, stack_b);
		return (0);
	}
	put_index(stack_a);
	choose_sort(stack_a, stack_b);
	free_both_stacks(stack_a, stack_b);
}
