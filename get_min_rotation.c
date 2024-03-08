/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_min_rotation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyupar <sehyupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 17:13:08 by sehyupar          #+#    #+#             */
/*   Updated: 2024/03/08 17:24:16 by sehyupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_ascending(t_node *x, t_node *y)
{
	if (!x || !y)
		return (-1);
	if (x->data > y->data)
		return (0);
	return (1);
}

int	get_b_data(t_stack *b, int b_idx)
{
	t_node	*p;
	int		idx;

	idx = 0;
	p = b->top;
	while (idx++ < b_idx)
		p = p->next;
	return (p->data);
}

int	a_index(t_stack *a, t_stack *b, int b_idx)
{
	t_node	*p;
	int		idx;
	int		b_data;

	idx = 0;
	p = a->top;
	b_data = get_b_data(b, b_idx);
	while (p && is_ascending(p->prev, p) && p->data < b_data)
	{
		idx++;
		p = p->next;
	}
	if (idx == 0 && a->bottom->data > b_data)
	{
		p = a->bottom;
		idx = a->size;
		while (p && is_ascending(p, p->next) && b_data < p->data)
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
		a -= (na);
	if (b > (int)(nb / 2 + 0.5))
		b -= (nb);
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

t_rotation	get_min_rotation(t_stack *a, t_stack *b)
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
		a_idx = a_index(a, b, b_idx);
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
