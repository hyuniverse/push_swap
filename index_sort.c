/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyupar <sehyupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:57:24 by sehyupar          #+#    #+#             */
/*   Updated: 2024/02/23 14:17:19 by sehyupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_index(t_index *index, int l, int r)
{
	t_index	tmp;

	tmp = index[l];
	index[l] = index[r];
	index[r] = tmp;
}

int	partition(t_index *index, int l, int r, int k)
{
	int		i;
	int		j;
	t_index	p;

	p = index[k];
	i = l;
	j = r - 1;
	swap_index(index, k, r);
	while (i <= j)
	{
		while (i <= j && index[i].data <= p.data)
			i++;
		while (i <= j && index[j].data >= p.data)
			j--;
		if (i < j)
			swap_index(index, i, j);
	}
	swap_index(index, i, r);
	return (i);
}

void	r_quick_sort(t_index *index, int l, int r)
{
	int	k;
	int	m;

	if (l < r)
	{
		k = (int)((l + r) / 2);
		m = partition(index, l, r, k);
		r_quick_sort(index, l, m - 1);
		r_quick_sort(index, m + 1, r);
	}
}

void	quick_sort(t_index *index, int n)
{
	r_quick_sort(index, 0, n - 1);
}
