/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 15:43:47 by cesnault          #+#    #+#             */
/*   Updated: 2016/11/15 10:24:56 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

t_list	*ft_lstnew(void	const *content, size_t content_size)
{
	t_list	*cell;
	size_t	size;
	void	*src;

	size = content_size;
	src = ft_strnew(content_size);
	if (!(cell = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		cell->content = NULL;
		cell->content_size = 0;
		cell->next = NULL;
	}
	else
	{
		cell->content = ft_memcpy(src, content, content_size);
		cell->content_size = size;
		cell->next = NULL;
	}
	return (cell);
}
