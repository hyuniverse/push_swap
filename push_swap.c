/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyupar <sehyupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:36:11 by sehyupar          #+#    #+#             */
/*   Updated: 2024/03/05 21:48:03 by sehyupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	a_index(t_stack *a, t_stack *b, int b_idx, int max)
{
	t_node	*p;
	int		idx;
	int		b_data;

	idx = 0;
	p = b->top;
	while (idx++ < b_idx)
		p = p->next;
	b_data = p->data;
	idx = 0;
	p = a->top;
	while (p && p->data < b_data)
	{
		idx++;
		p = p->next;
	}
	if (idx == 0 && a->bottom->data > b_data)
	{
		p = a->bottom;
		idx = a->size + 1;
		while (p && b_data < p->data && p->data < max)
		{
			idx--;
			p = p->prev;
		}
	}
	return (idx);
}

t_rotation	calc_roatation(int a, int b, int na, int nb)
{
	t_rotation	rot;

	if (a > (int)(na / 2 + 0.5))
		a -= na;
	if (b > (int)(nb / 2 + 0.5))
		b -= nb;
	if (a >= 0 && b >= 0)
		rot.total = a + b;
	else if (a < 0 && b < 0)
		rot.total = (a + b) * (-1);
	else if (a < 0 && b >= 0)
		rot.total = b - a;
	else
		rot.total = a - b;
	rot.a = a;
	rot.b = b;
	return (rot);
}

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

t_rotation	get_min_rotation(t_stack *a, t_stack *b, int max)
{
	t_rotation	min;
	t_rotation	tmp;
	int			b_idx;
	int			a_idx;

	b_idx = 0;
	min.a = 0;
	min.b = 0;
	min.total = INT_MAX;
	while (b_idx < b->size)
	{
		a_idx = a_index(a, b, b_idx, max);
		tmp = calc_roatation(a_idx, b_idx, a->size, b->size);
		if (tmp.total < min.total)
		{
			min.a = tmp.a;
			min.b = tmp.b;
			min.total = tmp.total;
		}
		b_idx++;
	}
	return (min);
}

void	push_swap(t_stack *a, t_stack *b)
{
	int			pivot1;
	int			pivot2;
	t_rotation	rot;
	int			n;

	pivot1 = (int)(a->size / 3);
	pivot2 = (int)(a->size / 3) * 2;
	n = a->size;
	while (a->size > n - pivot2)
	{
		if (a->top->data < pivot2)
		{
			p(a, b);
			if (b->top->data >= pivot1)
				r(b, 1);
		}
		r(a, 1);
	}
	while (a->size > 1)
		p(a, b);
	n = a->top->data;
	while (b->size)
	{
		rot = get_min_rotation(a, b, n);
		rotate_stacks(a, b, &rot);
		if (b->top->data > n)
			n = b->top->data;
		p(b, a);
	}
	final_rotation(a);
	//print_status(a, b);
}
