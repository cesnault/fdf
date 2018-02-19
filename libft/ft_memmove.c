/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 18:24:46 by cesnault          #+#    #+#             */
/*   Updated: 2016/11/15 10:27:59 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t index;

	index = 0;
	while (index < len && ((src + index) != dst))
		index++;
	if ((src + index) == dst)
	{
		index = len;
		while (index > 0)
		{
			*((unsigned char*)(dst + index - 1)) =
				*((unsigned char *)(src + index - 1));
			index--;
		}
		return (dst);
	}
	index = 0;
	while (index < len)
	{
		*((unsigned char *)dst + index) = *(((unsigned char *)src + index));
		index++;
	}
	return (dst);
}
