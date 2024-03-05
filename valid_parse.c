/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyupar <sehyupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:53:35 by sehyupar          #+#    #+#             */
/*   Updated: 2024/02/22 21:55:02 by sehyupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	indexing(t_index *index)
{
	int	i;

	i = 0;
	while (i < INT_MAX && index[i].data)
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
		return (0);
	//만약 len == 0일 경우 음수이거나 숫자 아닌게 온거임. 
	num = ft_atoi(*p);
	if (num < 1 || num > INT_MAX)
		return (0);
	*p += len;
	return (num);
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
				if (!num)
					return (0);
				a->push_bottom(a, get_node(num));
				index[j].data = num;
				index[j++].node = a->bottom;
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
		n = indexing(index);
	}
	free(index);
	return (n);
}
