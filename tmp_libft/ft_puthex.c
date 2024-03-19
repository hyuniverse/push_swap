/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyupar <sehyupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 21:00:15 by sehyupar          #+#    #+#             */
/*   Updated: 2024/03/19 16:39:26 by sehyupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	puthex(unsigned long nbr, int len, char mode)
{
	char	*ch1;
	char	*ch2;
	int		cnt;
	int		n;

	ch1 = "0123456789abcdef";
	ch2 = "0123456789ABCDEF";
	if (len == 0 || nbr == 0)
		return (0);
	cnt = puthex(nbr / 16, len - 1, mode);
	if (cnt == -1)
		return (-1);
	if (mode == 'l')
		n = write(1, ch1 + nbr % 16, 1);
	if (mode == 'u')
		n = write(1, ch2 + nbr % 16, 1);
	if (n < 0)
		return (-1);
	cnt += n;
	return (cnt);
}

int	ft_puthex(long n, int bits, char mode)
{
	int		cnt;

	if (bits == 16)
	{
		if (write(1, "0x", 2) < 0)
			return (-1);
	}
	if (n == 0)
		cnt = write(1, "0", 1);
	else
			cnt = puthex((unsigned long)n, bits, mode);
	if (bits == 16 && cnt >= 0)
		cnt += 2;
	return (cnt);
}
