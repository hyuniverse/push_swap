/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyupar <sehyupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:58:06 by sehyupar          #+#    #+#             */
/*   Updated: 2024/03/22 14:54:59 by sehyupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sab(t_stack *a, t_stack	*b, int type)
{
	if (a->size < 2 || b->size < 2)
		return ;
	s(a, 2);
	s(b, 2);
	if (type == 1)
		write(1, "ss\n", 3);
}

void	rab(t_stack *a, t_stack	*b, int type)
{
	if (a->size < 2 || b->size < 2)
		return ;
	r(a, 2);
	r(b, 2);
	if (type == 1)
		write(1, "rr\n", 3);
}

void	rrab(t_stack *a, t_stack *b, int type)
{
	if (a->size < 2 || b->size < 2)
		return ;
	rr(a, 2);
	rr(b, 2);
	if (type == 1)
		write(1, "rrr\n", 4);
}
