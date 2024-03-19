/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyupar <sehyupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 18:32:42 by sehyupar          #+#    #+#             */
/*   Updated: 2023/12/12 21:19:12 by sehyupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	in_set(char c, char const *set)
{
	while (*set)
		if (c == *(set++))
			return (1);
	return (0);
}

static const char	*cnt_valid_char(char const *s1, char const *set, int *len)
{
	*len = (int)ft_strlen(s1);
	while (*s1)
	{
		if (!in_set(*s1, set))
			break ;
		s1++;
		(*len)--;
	}
	while (*len > 0)
	{	
		if (!in_set(s1[*len - 1], set))
			break ;
		(*len)--;
	}
	return (s1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*s;
	const char	*start;
	int			len;
	int			i;

	if (!s1 && !set)
		return (0);
	start = cnt_valid_char(s1, set, &len);
	s = (char *)malloc(len + 1);
	if (!s)
		return (0);
	i = 0;
	while (i < len)
		s[i++] = *(start++);
	s[i] = 0;
	return (s);
}
