/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyupar <sehyupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:18:45 by sehyupar          #+#    #+#             */
/*   Updated: 2024/02/21 19:35:54 by sehyupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	s(t_stack *stack, int type)
{
	stack->swap(stack);
	if (type == 1)
		printf("s%c\n", stack->name);
}

void	p(t_stack *u, t_stack *v)
{
	t_node	*tmp;

	tmp = u->pop_top(u);
	v->push_top(v, tmp);
	printf("p%c\n", v->name);
}

void	r(t_stack *stack, int type)
{
	t_node	*tmp;

	tmp = stack->pop_top(stack);
	stack->push_bottom(stack, tmp);
	if (type == 1)
		printf("r%c\n", stack->name);
}

void	rr(t_stack *stack, int type)
{
	t_node	*tmp;

	tmp = stack->pop_bottom(stack);
	stack->push_top(stack, tmp);
	if (type == 1)
		printf("rr%c\n", stack->name);
}
