/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyupar <sehyupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 19:10:15 by sehyupar          #+#    #+#             */
/*   Updated: 2024/03/12 17:08:53 by sehyupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a_stack(t_stack *a, t_rotation *rot)
{
	if (rot->a < 0)
	{
		while (rot->a)
		{
			rr(a, 1);
			rot->a++;
		}
	}
	else
	{
		while (rot->a)
		{
			r(a, 1);
			rot->a--;
		}
	}
}

void	rotate_b_stack(t_stack *b, t_rotation *rot)
{
	if (rot->b < 0)
	{
		while (rot->b)
		{
			rr(b, 1);
			rot->b++;
		}
	}
	else
	{
		while (rot->b)
		{
			r(b, 1);
			rot->b--;
		}
	}
}

void	rotate_stacks(t_stack *a, t_stack *b, t_rotation *rot)
{
	if (rot->a > 0 && rot->b > 0)
	{
		while (rot->a && rot->b)
		{
			rab(a, b, 1);
			rot->a--;
			rot->b--;
		}
	}
	else if (rot->a < 0 && rot->b < 0)
	{
		while (rot->a && rot->b)
		{
			rrab(a, b, 1);
			rot->a++;
			rot->b++;
		}
	}
	rotate_a_stack(a, rot);
	rotate_b_stack(b, rot);
}
