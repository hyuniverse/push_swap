/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyupar <sehyupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:20:42 by sehyupar          #+#    #+#             */
/*   Updated: 2024/02/21 17:18:21 by sehyupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_stack *stack, char name)
{
	stack->name = name;
	stack->pop_bottom = pop_bottom;
	stack->pop_top = pop_top;
	stack->push_bottom = push_bottom;
	stack->push_top = push_top;
	stack->swap = swap;
	stack->top = 0;
	stack->bottom = 0;
	stack->size = 0;
}

t_node	*get_node(int data)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (0);
	node->data = data;
	node->prev = 0;
	node->next = 0;
	return (node);
}

void	free_nodes(t_node *node)
{
	if (node->next)
		free_nodes(node->next);
	free(node);
}
