/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyupar <sehyupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 21:00:15 by sehyupar          #+#    #+#             */
/*   Updated: 2023/12/07 22:07:42 by sehyupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	putnbr(long long int n, int fd)
{
	char	ch;

	if (n == 0)
		return ;
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	ch = '0' + (n % 10);
	putnbr(n / 10, fd);
	write(fd, &ch, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == 0)
		write(fd, "0", 1);
	else
		putnbr(n, fd);
}
