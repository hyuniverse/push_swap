/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyupar <sehyupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 21:48:17 by sehyupar          #+#    #+#             */
/*   Updated: 2024/03/08 17:15:48 by sehyupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	case_r(t_stack *a)
{
	int	x;
	int	y;
	int	z;

	x = a->top->data;
	y = a->top->next->data;
	z = a->bottom->data;
	if (x > y && y < z && x > z)
		return (1);
	return (0);
}

int	case_rr(t_stack *a)
{
	int	x;
	int	y;
	int	z;

	x = a->top->data;
	y = a->top->next->data;
	z = a->bottom->data;
	if (x < y && y > z && x > z)
		return (1);
	return (0);
}

int	case_swap(t_stack *a)
{
	if (case_r(a) || case_rr(a))
		return (0);
	return (1);
}

void	sort3(t_stack *a)
{
	if (a->size == 2 && a->top > a->bottom)
		s(a, 1);
	else if (a->size == 3)
	{	
		if (case_swap(a))
			s(a, 1);
		if (case_r(a))
			r(a, 1);
		else if (case_rr(a))
			rr(a, 1);
	}
}
