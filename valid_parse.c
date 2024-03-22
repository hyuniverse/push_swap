/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyupar <sehyupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:53:35 by sehyupar          #+#    #+#             */
/*   Updated: 2024/03/22 14:57:10 by sehyupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	indexing(t_index *index, int n)
{
	int	i;

	i = 0;
	while (i < INT_MAX && i < n)
	{
		if (i > 0 && index[i].data == index[i - 1].data)
			return (0);
		index[i].node->data = i;
		i++;
	}
	return (1);
}

long	valid_num(char **p)
{
	int		len;
	long	num;

	len = 0;
	if (**p == '-')
		len++;
	while ((*p + len) && ft_isdigit(*(*p + len)))
		len++;
	if ((len > 10 && **p == '-' && ft_strncmp(*p, "-2147483648", 11) > 0) || \
	(len > 9 && **p != '-' && ft_strncmp(*p, "2147483647", 10) > 0) || \
	(*(*p + len) && !is_space(*(*p + len))))
		return (UNVALID_NUM);
	num = ft_atoi(*p);
	*p += len;
	return (num);
}

void	add_index_list(t_stack *a, t_index *index, int idx, int data)
{
	a->push_bottom(a, get_node(data));
	index[idx].data = data;
	index[idx].node = a->bottom;
}

int	parse(char	**argv, t_stack *a, t_index *index)
{
	char	*p;
	long	num;
	int		i;
	int		j;

	i = 1;
	j = 0;
	while (argv[i])
	{
		p = argv[i++];
		while (*p)
		{
			while (*p && is_space(*p))
				p++;
			if (*p)
			{
				num = valid_num(&p);
				if (num == UNVALID_NUM)
					return (0);
				add_index_list(a, index, j++, num);
			}
		}
	}
	return (j);
}

int	valid(char	**argv, t_stack *a)
{
	t_index	*index;
	int		n;

	index = (t_index *)malloc(sizeof(t_index) * INT_MAX);
	if (!index)
		return (0);
	n = parse(argv, a, index);
	if (n)
	{
		quick_sort(index, n);
		n = indexing(index, n);
	}
	free(index);
	return (n);
}
