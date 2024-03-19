/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyupar <sehyupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 19:04:55 by sehyupar          #+#    #+#             */
/*   Updated: 2023/12/12 23:25:18 by sehyupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ret;
	size_t	i;

	ret = malloc(size * count);
	if (!ret)
		return (0);
	i = 0;
	while (i < size * count)
	{
		*((char *)ret + i) = 0;
		i++;
	}
	return (ret);
}
