/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyupar <sehyupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 19:06:05 by sehyupar          #+#    #+#             */
/*   Updated: 2023/12/07 22:04:08 by sehyupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	if (dst == src || !len)
		return (dst);
	if (dst < src)
		return (ft_memcpy(dst, src, len));
	i = len;
	while (i > 0)
	{
		--i;
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
	}
	return (dst);
}
