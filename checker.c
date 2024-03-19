/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyupar <sehyupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:46:46 by sehyupar          #+#    #+#             */
/*   Updated: 2024/03/19 19:11:39 by sehyupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_op(t_stack *a, t_stack *b, char *str)
{
	if (ft_strncmp(str, "sa\n", 3) == 0)
		s(a, 2);
	else if (ft_strncmp(str, "sb\n", 3) == 0)
		s(b, 2);
	else if (ft_strncmp(str, "ss\n", 3) == 0)
		sab(a, b, 2);
	else if (ft_strncmp(str, "pa\n", 3) == 0)
		p(b, a, 2);
	else if (ft_strncmp(str, "pb\n", 3) == 0)
		p(a, b, 2);
	else if (ft_strncmp(str, "ra\n", 3) == 0)
		r(a, 2);
	else if (ft_strncmp(str, "rb\n", 3) == 0)
		r(b, 2);
	else if (ft_strncmp(str, "rr\n", 3) == 0)
		rab(a, b, 2);
	else if (ft_strncmp(str, "rra\n", 4) == 0)
		rr(a, 2);
	else if (ft_strncmp(str, "rrb\n", 4) == 0)
		rr(b, 2);
	else if (ft_strncmp(str, "rrr\n", 4) == 0)
		rrab(a, b, 2);
	else
		return (0);
	return (1);
}

int	check_push_swap(t_stack *a, t_stack *b)
{
	char	*str;

	while (1)
	{
		str = get_next_line(0);
		if (!str)
			return (1);
		else if (!check_op(a, b, str))
		{
			ft_putstr_fd("ERROR\n", 2);
			free(str);
			return (0);
		}
		free(str);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	int		n;

	init_stack(&a, 'a');
	init_stack(&b, 'b');
	if (argc > 1 && valid(argv, &a))
	{
		n = check_push_swap(&a, &b);
		if (n && !is_sorted(&a, 1))
			ft_putstr_fd("KO\n", 1);
		else if (n)
			ft_putstr_fd("OK\n", 1);
	}
	else if (argc > 1)
		ft_putstr_fd("ERROR\n", 3);
	if (a.top)
		free_nodes(a.top);
	if (b.top)
		free_nodes(b.top);
	return (0);
}
