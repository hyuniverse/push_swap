/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyupar <sehyupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 20:35:31 by sehyupar          #+#    #+#             */
/*   Updated: 2023/12/12 23:02:00 by sehyupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		len;
	char	*iter;
	int		i;

	if (!s)
		return (0);
	len = ft_strlen(s);
	iter = (char *)malloc(sizeof(char) * (len + 1));
	if (!iter)
		return (0);
	i = 0;
	while (s[i])
	{
		iter[i] = f(i, s[i]);
		i++;
	}
	iter[i] = 0;
	return (iter);
}
