/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 08:11:32 by cesnault          #+#    #+#             */
/*   Updated: 2016/12/08 09:46:18 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <unistd.h>

void	copybuffer(t_content *cell, int *ind, char **str1, char **str2)
{
	while (cell->buf[*ind] != '\n' && *ind <= cell->ret)
		(*ind)++;
	if (cell->tmp == NULL)
		cell->tmp = ft_strsub(cell->buf, cell->beg, *ind - cell->beg);
	else
	{
		*str2 = ft_strsub(cell->buf, cell->beg, *ind - cell->beg);
		cell->tmp = ft_strjoin(cell->tmp, *str2);
		free(*str1);
		free(*str2);
	}
}

int		get_next_line2(t_content *cell, int *ind, int fd, char **line)
{
	if (*ind > cell->ret)
	{
		ft_bzero(cell->buf, BUFF_SIZE);
		cell->beg = 0;
		if (cell->ret < BUFF_SIZE)
		{
			*line = cell->tmp;
			cell->tmp = NULL;
			return (1);
		}
		return (get_next_line(fd, line));
	}
	*line = cell->tmp;
	cell->tmp = NULL;
	if (*ind + 1 == cell->ret)
	{
		ft_bzero(cell->buf, BUFF_SIZE);
		cell->beg = 0;
		return (1);
	}
	else
		cell->beg = *ind + 1;
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static t_content	cell;
	int					ind;
	char				*str1;
	char				*str2;

	ind = cell.beg;
	str1 = cell.tmp;
	if (cell.buf[0] == 0)
		if ((cell.ret = read(fd, cell.buf, BUFF_SIZE)) < 0)
			return (-1);
	if (cell.ret != 0)
		copybuffer(&cell, &ind, &str1, &str2);
	if (cell.ret == 0)
	{
		ft_bzero(cell.buf, BUFF_SIZE);
		cell.beg = 0;
		if (cell.tmp != NULL)
		{
			*line = cell.tmp;
			cell.tmp = NULL;
			return (1);
		}
		return (0);
	}
	return (get_next_line2(&cell, &ind, fd, line));
}
