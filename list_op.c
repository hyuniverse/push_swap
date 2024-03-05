/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyupar <sehyupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:18:21 by sehyupar          #+#    #+#             */
/*   Updated: 2024/02/27 21:41:26 by sehyupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_top(t_stack *stack, t_node *node)
{
	if (stack->size == 0)
	{
		stack->top = node;
		stack->bottom = node;
	}
	else
	{
		stack->top->prev = node;
		node->next = stack->top;
		stack->top = node;
	}
	node->prev = 0;
	stack->size++;
}

void	push_bottom(t_stack *stack, t_node *node)
{
	if (stack->size == 0)
	{
		stack->top = node;
		stack->bottom = node;
	}
	else
	{
		stack->bottom->next = node;
		node->prev = stack->bottom;
		stack->bottom = node;
	}
	node->next = 0;
	stack->size++;
}

t_node	*pop_top(t_stack *stack)
{
	t_node	*node;

	if (stack->size == 0)
		return (0);
	node = stack->top;
	stack->top = node->next;
	if (stack->size == 1)
		stack->bottom = 0;
	else
		stack->top->prev = 0;
	stack->size--;
	node->next = 0;
	return (node);
}

t_node	*pop_bottom(t_stack *stack)
{
	t_node	*node;

	if (stack->size == 0)
		return (0);
	node = stack->bottom;
	stack->bottom = node->prev;
	if (stack->size == 1)
		stack->top = 0;
	else
		stack->bottom->next = 0;
	stack->size--;
	node->prev = 0;
	return (node);
}

void	swap(t_stack *stack)
{
	t_node	*tmp;

	if (stack->size < 2)
		return ;
	tmp = stack->top;
	tmp->prev = tmp->next;
	tmp->next->next = tmp;
	tmp->next->prev = 0;
	stack->top = tmp->next;
	if (stack->size == 2)
	{
		stack->bottom = tmp;
		tmp->next = 0;
	}
}
