/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putusg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyupar <sehyupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 21:00:15 by sehyupar          #+#    #+#             */
/*   Updated: 2024/03/19 16:39:32 by sehyupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	putusg(unsigned long nbr)
{
	char	ch;
	int		cnt;
	int		n;

	cnt = 0;
	if (nbr == 0)
		return (0);
	ch = '0' + (nbr % 10);
	cnt += putusg(nbr / 10);
	if (cnt == -1)
		return (-1);
	n = write(1, &ch, 1);
	if (n < 0)
		return (-1);
	cnt += n;
	return (cnt);
}

int	ft_putusg(unsigned int n)
{
	int	cnt;

	if (n == 0)
		cnt = write(1, "0", 1);
	else
		cnt = putusg(n);
	return (cnt);
}
