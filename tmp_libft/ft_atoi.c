/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyupar <sehyupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 19:04:37 by sehyupar          #+#    #+#             */
/*   Updated: 2023/12/07 22:04:50 by sehyupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nbr)
{
	int		n;
	int		sign;

	n = 0;
	sign = 1;
	while (*nbr == 32 || (*nbr >= 9 && *nbr <= 13))
		nbr++;
	if (*nbr == '+' || *nbr == '-')
	{
		if (*nbr == '-')
			sign *= (-1);
		nbr++;
	}
	while (*nbr >= '0' && *nbr <= '9')
	{
		n *= 10;
		n += *nbr - '0';
		nbr++;
	}
	return (sign * n);
}
