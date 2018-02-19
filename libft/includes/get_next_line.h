/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 09:48:28 by cesnault          #+#    #+#             */
/*   Updated: 2016/12/20 12:38:47 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 500
# include <stdlib.h>

typedef struct	s_content
{
	char	buf[BUFF_SIZE];
	char	*tmp;
	int		beg;
	int		ret;
}				t_content;

int				get_next_line(const int fd, char **line);
#endif
