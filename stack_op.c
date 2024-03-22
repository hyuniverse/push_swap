/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyupar <sehyupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:18:45 by sehyupar          #+#    #+#             */
/*   Updated: 2024/03/22 14:54:30 by sehyupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	s(t_stack *stack, int type)
{
	char	*str;

	if (stack->size < 2)
		return ;
	stack->swap(stack);
	if (type == 1)
	{
		str = (char *)malloc(4);
		str[0] = 's';
		str[1] = stack->name;
		str[2] = '\n';
		str[3] = 0;
		write(1, str, 3);
		free(str);
	}
}

void	p(t_stack *u, t_stack *v, int type)
{
	char	*str;
	t_node	*tmp;

	if (u->size < 1)
		return ;
	tmp = u->pop_top(u);
	v->push_top(v, tmp);
	if (type == 1)
	{
		str = (char *)malloc(4);
		str[0] = 'p';
		str[1] = v->name;
		str[2] = '\n';
		str[3] = 0;
		write(1, str, 3);
		free(str);
	}	
}

void	r(t_stack *stack, int type)
{
	char	*str;
	t_node	*tmp;

	if (stack->size < 2)
		return ;
	tmp = stack->pop_top(stack);
	stack->push_bottom(stack, tmp);
	if (type == 1)
	{
		str = (char *)malloc(4);
		str[0] = 'r';
		str[1] = stack->name;
		str[2] = '\n';
		str[3] = 0;
		write(1, str, 3);
		free(str);
	}
}

void	rr(t_stack *stack, int type)
{
	char	*str;
	t_node	*tmp;

	if (stack->size < 2)
		return ;
	tmp = stack->pop_bottom(stack);
	stack->push_top(stack, tmp);
	if (type == 1)
	{
		str = (char *)malloc(4);
		str[0] = 'r';
		str[1] = 'r';
		str[2] = stack->name;
		str[3] = '\n';
		str[4] = 0;
		write(1, str, 4);
		free(str);
	}
}
