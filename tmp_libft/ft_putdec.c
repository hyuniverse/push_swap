/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyupar <sehyupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 21:00:15 by sehyupar          #+#    #+#             */
/*   Updated: 2023/12/30 03:24:09 by sehyupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	putdec(long nbr)
{
	char	ch;
	int		cnt;
	int		n;

	cnt = 0;
	if (nbr == 0)
		return (0);
	if (nbr < 0)
	{
		n = write(1, "-", 1);
		if (n < 0)
			return (-1);
		cnt += n;
		nbr = -nbr;
	}
	ch = '0' + (nbr % 10);
	cnt += putdec(nbr / 10);
	if (cnt == -1)
		return (-1);
	n = write(1, &ch, 1);
	if (n < 0)
		return (-1);
	cnt += n;
	return (cnt);
}

int	ft_putdec(int n)
{
	int	cnt;

	if (n == 0)
		cnt = write(1, "0", 1);
	else
		cnt = putdec(n);
	return (cnt);
}
