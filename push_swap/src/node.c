/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveil <aleveil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 10:20:36 by aleveil           #+#    #+#             */
/*   Updated: 2022/11/21 10:20:38 by aleveil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node	*create_node(int nb)
{
	t_node	*node;

	node = (t_node *) malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = nb;
	node->index = -1;
	node->next = NULL;
	return (node);
}

t_node	*node_last(t_node *head)
{
	t_node	*tmp;

	if (!head)
		return (NULL);
	tmp = head;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

void	add_node_top(t_node **stack, t_node *node)
{
	if (!node)
		return ;
	node->next = *stack;
	*stack = node;
}

void	add_node_bot(t_node **stack, t_node *node)
{
	t_node	*temp;

	if (!node)
		return ;
	if (*stack)
	{
		temp = node_last(*stack);
		temp->next = node;
	}
	else
		*stack = node;
}
