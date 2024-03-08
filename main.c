/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyupar <sehyupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:16:44 by sehyupar          #+#    #+#             */
/*   Updated: 2024/03/07 18:06:29 by sehyupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	leak_check(void)
{
	system("leaks push_swap");
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	init_stack(&a, 'a');
	init_stack(&b, 'b');
	if (argc > 1 && valid(argv, &a))
	{
		if (!is_sorted(&a, 1))
			push_swap(&a, &b);
	}
	else if (argc > 1)
		ft_putstr_fd("ERROR\n", 2);
	if (a.top)
		free_nodes(a.top);
	if (b.top)
		free_nodes(b.top);
	return (0);
}
