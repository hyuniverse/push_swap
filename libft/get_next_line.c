/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyupar <sehyupar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 13:14:03 by sehyupar          #+#    #+#             */
/*   Updated: 2024/03/20 19:59:26 by sehyupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	partial_line_cpy(int fd, t_tmp *tmp, t_buf *rd)
{
	int			len;

	if (read(fd, &len, 0) < 0)
		return (-1);
	len = 0;
	while (len < tmp->size)
	{
		if (rd->i == 0)
			rd->n = read(fd, rd->buf, BUFFER_SIZE);
		if (rd->n < 0)
			return (-1);
		while (rd->i < rd->n && len < tmp->size)
		{
			tmp->buf[len++] = rd->buf[rd->i];
			if (rd->buf[rd->i++] == '\n')
				break ;
		}
		if (rd->i == BUFFER_SIZE)
			rd->i = 0;
		if (rd->n < BUFFER_SIZE || tmp->buf[len - 1] == '\n')
			break ;
	}
	return (len);
}

char	*whole_line_cpy(int fd, t_tmp *tmp, t_buf *rd, int *i)
{
	char	*str;

	rd->len += *i;
	if (*i < tmp->size || tmp->buf[*i - 1] == '\n')
		str = (char *)malloc(rd->len + 1);
	else
		str = get_next_line(fd);
	if (!str)
		return (0);
	if (*i < tmp->size || tmp->buf[*i - 1] == '\n')
		str[rd->len] = 0;
	while (--*i >= 0)
		str[--rd->len] = tmp->buf[*i];
	return (str);
}

char	*get_next_line(int fd)
{
	static t_buf	rd;
	t_tmp			tmp;
	char			*str;
	int				i;

	tmp.size = 512 * (BUFFER_SIZE < 512) + BUFFER_SIZE * (BUFFER_SIZE >= 512);
	tmp.buf = (char *)malloc(tmp.size);
	if (!tmp.buf)
		return (0);
	i = partial_line_cpy(fd, &tmp, &rd);
	if (rd.n == rd.i || i == -1)
		init_static(&rd);
	if (i == -1)
		rd.len = 0;
	if (i < 0 || (rd.len == 0 && i == 0))
		str = 0;
	else
		str = whole_line_cpy(fd, &tmp, &rd, &i);
	free(tmp.buf);
	i = 0;
	while (i < 10000)
		i++;
	return (str);
}
