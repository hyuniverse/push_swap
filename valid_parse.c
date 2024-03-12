/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyupar <sehyupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:53:35 by sehyupar          #+#    #+#             */
/*   Updated: 2024/03/12 17:22:05 by sehyupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	valid_num(char **p)
{
	int	len;
	int	num;

	len = 0;
	while ((*p + len) && ft_isdigit(*(*p + len)))
		len++;
	if (len > 10 || (*(*p + len) && !is_space(*(*p + len))))
		return (-1);
	num = ft_atoi(*p);
	if (num < 0 || num > INT_MAX)
		return (-1);
	*p += len;
	return (num);
}

void	name_morohazi(t_stack *a, t_index *index, int idx, int data)
{
	a->push_bottom(a, get_node(data));
	index[idx].data = data;
	index[idx].node = a->bottom;
}

int	parse(char	**argv, t_stack *a, t_index *index)
{
	char	*p;
	int		num;
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
				if (num < 0)
					return (0);
				name_morohazi(a, index, j++, num);
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
