/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyupar <sehyupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 19:06:46 by sehyupar          #+#    #+#             */
/*   Updated: 2023/12/12 21:10:41 by sehyupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	n;

	i = 0;
	n = ft_strlen(needle);
	if (!*needle)
		return ((char *)haystack);
	while (haystack[i] && i + n <= len)
	{
		if (haystack[i] == *needle)
			if (!ft_strncmp(&haystack[i], needle, n))
				return ((char *)haystack + i);
		i++;
	}
	return (0);
}
