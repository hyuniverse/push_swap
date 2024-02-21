/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyupar <sehyupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 12:41:30 by sehyupar          #+#    #+#             */
/*   Updated: 2024/02/21 18:59:28 by sehyupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

# include <stdio.h> //지우기

typedef struct s_node
{
	int				data;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	char	name;
	t_node	*top;
	t_node	*bottom;
	int		size;
	void	(*push_top)(struct s_stack*, t_node*);
	void	(*push_bottom)(struct s_stack*, t_node*);
	t_node	*(*pop_top)(struct s_stack*);
	t_node	*(*pop_bottom)(struct s_stack*);
	void	(*swap)(struct s_stack*);
}	t_stack;

int		ft_isdigit(int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_printf(const char *str, ...);
size_t	ft_strlen(const char *s);

void	init_stack(t_stack *stack, char name);

t_node	*get_node(int data);
void	free_nodes(t_node *node);
void	push_top(t_stack *stack, t_node *node);
void	push_bottom(t_stack *stack, t_node *node);
t_node	*pop_top(t_stack *stack);
t_node	*pop_bottom(t_stack *stack);
void	swap(t_stack *stack);

void	s(t_stack *stack, int type);
void	p(t_stack *u, t_stack *v);
void	r(t_stack *stack, int type);
void	rr(t_stack *stack, int type);
void	sab(t_stack *a, t_stack	*b);
void	rab(t_stack *a, t_stack	*b);
void	rrab(t_stack *a, t_stack	*b);

#endif