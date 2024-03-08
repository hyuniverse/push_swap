/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyupar <sehyupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:36:11 by sehyupar          #+#    #+#             */
/*   Updated: 2024/03/08 17:13:42 by sehyupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	final_rotation(t_stack *a)
{
	int			idx;
	t_node		*p;

	idx = 0;
	p = a->top;
	while (p && p->data != 0)
	{
		idx++;
		p = p->next;
	}
	if (idx > (int)(a->size / 2 + 0.5))
	{
		idx -= a->size;
		while (idx++ != 0)
			rr(a, 1);
	}
	else
	{
		while (idx-- != 0)
			r(a, 1);
	}
}

void	push_to_b(t_stack *a, t_stack *b)
{
	int			pivot1;
	int			pivot2;
	int			n;

	pivot1 = (int)(a->size / 3);
	pivot2 = (int)(a->size / 3 * 2.5);
	n = a->size;
	if (a->size > 5)
	{
		while (a->size > 3 && a->size > n - pivot2)
		{
			if (a->top->data < pivot2)
			{
				p(a, b);
				if (b->top->data >= pivot1)
					r(b, 1);
			}
			else
				r(a, 1);
		}
	}
	while (a->size > 3)
		p(a, b);
}

void	push_swap(t_stack *a, t_stack *b)
{
	t_rotation	rot;

	push_to_b(a, b);
	if (a->size > 1 && !is_sorted(a, 2))
		sort3(a);
	while (b->size)
	{
		rot = get_min_rotation(a, b);
		rotate_stacks(a, b, &rot);
		p(b, a);
	}
	final_rotation(a);
}
