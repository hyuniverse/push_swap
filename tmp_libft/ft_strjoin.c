/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyupar <sehyupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 18:18:26 by sehyupar          #+#    #+#             */
/*   Updated: 2023/12/12 22:29:19 by sehyupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	char	*p;
	int		len;

	if (!s1 && !s2)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2);
	s = (char *)malloc(len + 1);
	if (!s)
		return (0);
	p = s;
	while (*s1)
		*(p++) = *(s1++);
	while (*s2)
		*(p++) = *(s2++);
	*p = 0;
	return (s);
}
