/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyupar <sehyupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:16:44 by sehyupar          #+#    #+#             */
/*   Updated: 2024/02/21 16:56:23 by sehyupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char	**av)
{
	t_stack	a;
	t_stack	b;

	init_stack(&a, 'a');
	init_stack(&b, 'b');

	//a에 av내용 저장하면서 valid check하기
		//유효할 경우에만 정렬 알고리즘 실행
		//아닌 경우 그냥 free해주고 return (0);

	if (a.top)
		free(a.top);
	if (b.top)
		free(b.top);
	return (0);
}
 