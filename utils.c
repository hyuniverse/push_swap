/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyupar <sehyupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:20:42 by sehyupar          #+#    #+#             */
/*   Updated: 2024/02/22 21:33:32 by sehyupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_stack *stack, char name)
{
	stack->name = name;
	stack->pop_bottom = pop_bottom;
	stack->pop_top = pop_top;
	stack->push_bottom = push_bottom;
	stack->push_top = push_top;
	stack->swap = swap;
	stack->top = 0;
	stack->bottom = 0;
	stack->size = 0;
}

t_node	*get_node(int data)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (0);
	node->data = data;
	node->prev = 0;
	node->next = 0;
	return (node);
}

void	free_nodes(t_node *node)
{
	if (node->next)
		free_nodes(node->next);
	free(node);
}

int	is_space(char c)
{
	if (c == ' ')
		return (1);
	return (0);
}

void	print_status(t_stack *a, t_stack *b)
{
	t_node	*pa;
	t_node	*pb;

	pa = a->top;
	pb = b->top;
	printf("%10c  %10c\n", 'a', 'b');
	printf("-------------  -------------\n");
	while (pa && pb)
	{
		printf(" %10d  %10d \n", pa->data, pb->data);
		pa = pa->next;
		pb = pb->next;
	}
	while (pa)
	{
		printf(" %10d  \n", pa->data);
		pa = pa->next;
	}
	while (pb)
	{
		printf("%10c   %10d\n", ' ', pb->data);
		pb = pb->next;
	}
	printf("\n");
}
