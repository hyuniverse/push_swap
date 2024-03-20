/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyupar <sehyupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 19:06:49 by sehyupar          #+#    #+#             */
/*   Updated: 2023/12/12 23:37:09 by sehyupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*p;
	int		n;

	p = 0;
	n = ft_strlen(s);
	while (n >= 0)
	{
		if (s[n] == (unsigned char)c)
			return ((char *)(s + n));
		n--;
	}
	return (0);
}
