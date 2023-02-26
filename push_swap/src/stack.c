/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveil <aleveil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 10:20:22 by aleveil           #+#    #+#             */
/*   Updated: 2022/11/21 12:59:57 by aleveil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_all(char **str)
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

void	create_stack(char	**argv, int argc, t_node **stack)
{
	int			i;
	t_node		*new_node;

	i = 0;
	if (argc != 2)
		i = 1;
	while (argv[i])
	{
		new_node = create_node(ft_atoi(argv[i]));
		add_node_bot(stack, new_node);
		i++;
	}
	if (argc == 2)
		free_all(argv);
}

int	stack_is_sorted(t_node **stack)
{
	t_node	*current;

	current = *stack;
	if (!stack)
		exit(1);
	while (current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

int	stack_size(t_node *head)
{
	int	size;

	size = 0;
	while (head)
	{
		size++;
		head = head->next;
	}
	return (size);
}
