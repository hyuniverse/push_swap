/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyupar <sehyupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 19:06:24 by sehyupar          #+#    #+#             */
/*   Updated: 2023/12/12 21:32:52 by sehyupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	id;
	size_t	is;
	size_t	rslt;

	if (!dest && size <= 0)
		return (0);
	id = ft_strlen(dest);
	is = ft_strlen(src);
	if (size == 0 || size < id)
		return (is + size);
	rslt = id + is;
	while (*src && id < size - 1)
	{
		dest[id] = *src;
		id++;
		src++;
	}
	if (is != 0)
		dest[id] = '\0';
	return (rslt);
}
