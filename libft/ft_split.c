/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyupar <sehyupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 18:24:12 by sehyupar          #+#    #+#             */
/*   Updated: 2023/12/12 20:40:37 by sehyupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	cnt_word(char const *s, char c)
{
	int	cnt;

	cnt = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
			cnt++;
		while (*s && *s != c)
			s++;
	}
	return (cnt);
}

static int	get_len(const char *s, char c)
{
	int	len;

	len = 0;
	if (!s)
		return (0);
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static void	whole_free(char **a, int i)
{
	while (i >= 0)
		free(a[i--]);
	free(a);
}

static char	**do_split(char **a, const char *s, char c, int n)
{
	int	i;
	int	j;

	i = 0;
	while (i < n)
	{
		if (*s && *s != c)
		{
			a[i] = (char *)malloc(sizeof(char) * (get_len(s, c) + 1));
			if (!a[i])
			{
				whole_free(a, i);
				return (0);
			}
			j = 0;
			while (*s && *s != c)
				a[i][j++] = *(s++);
			a[i][j] = 0;
			i++;
		}
		while (*s && *s == c)
			s++;
	}
	a[i] = 0;
	return (a);
}

char	**ft_split(char const *s, char c)
{
	int		n;
	char	**a;

	if (!s)
		return (0);
	n = cnt_word(s, c);
	a = (char **)malloc(sizeof(char *) * (n + 1));
	if (!a)
		return (0);
	a = do_split(a, s, c, n);
	return (a);
}
