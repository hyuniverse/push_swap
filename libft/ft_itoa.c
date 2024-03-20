/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyupar <sehyupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 21:10:50 by sehyupar          #+#    #+#             */
/*   Updated: 2023/12/12 17:54:07 by sehyupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_size(int n)
{
	int		size;

	if (n == 0)
		return (1);
	size = 0;
	if (n < 0)
		size++;
	while (n != 0)
	{
		n /= 10;
		size++;
	}
	return (size);
}

static void	itoa(char **nbr, int n, int size)
{
	while (size >= 0 && n >= 0)
	{
		(*nbr)[--size] = n % 10 + '0';
		n /= 10;
		if (n == 0)
			break ;
	}
}

char	*ft_itoa(int n)
{
	int		size;
	char	*nbr;

	size = get_size(n);
	nbr = (char *)malloc(sizeof(char) * (size + 1));
	if (nbr == 0)
		return (0);
	nbr[size] = 0;
	if (n == -2147483648)
	{
		nbr[--size] = '8';
		n = -214748364;
	}
	if (n < 0)
	{
		nbr[0] = '-';
		n *= -1;
	}
	itoa(&nbr, n, size);
	return (nbr);
}
