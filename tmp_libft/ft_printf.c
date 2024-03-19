/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyupar <sehyupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 15:46:11 by sehyupar          #+#    #+#             */
/*   Updated: 2024/03/19 16:53:02 by sehyupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_conv(char ch)
{
	char	*set;

	set = "csdiuxXp";
	while (*set)
	{
		if (*set++ == ch)
			return (1);
	}
	return (0);
}

static int	print_char(va_list *ap, const char ch)
{
	unsigned char	*str;
	unsigned char	c;
	int				cnt;

	if (ch == 'c')
	{
		c = va_arg(*ap, unsigned int);
		cnt = write(1, &c, 1);
	}
	else
	{
		str = va_arg(*ap, unsigned char *);
		if (!str)
			cnt = write(1, "(null)", 6);
		else
			cnt = write(1, str, ft_strlen_unsigned(str));
	}
	return (cnt);
}

static int	print_num(va_list *ap, const char ch)
{
	int		num;
	long	addr;
	int		cnt;

	cnt = 0;
	if (ch == 'p')
	{
		addr = va_arg(*ap, long);
		cnt = ft_puthex(addr, 16, 'l');
	}
	else
	{
		num = va_arg(*ap, int);
		if (ch == 'd' || ch == 'i')
			cnt = ft_putdec(num);
		else if (ch == 'u')
			cnt = ft_putusg((unsigned int)num);
		else if (ch == 'x')
			cnt = ft_puthex(num, 8, 'l');
		else
			cnt = ft_puthex(num, 8, 'u');
	}
	return (cnt);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		cnt;
	int		n;

	va_start(ap, str);
	cnt = 0;
	while (str && *str)
	{
		if (*str == '%' && is_conv(*(++str)))
		{
			if (*str == 'c' || *str == 's')
				n = print_char(&ap, *str++);
			else
				n = print_num(&ap, *str++);
		}
		else
			n = write(1, str++, 1);
		if (n < 0)
			return (-1);
		else
			cnt += n;
	}
	va_end(ap);
	return (cnt);
}
