/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 16:28:52 by cesnault          #+#    #+#             */
/*   Updated: 2016/11/15 08:31:32 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *restrict dst, const void *restrict src, int c,
		size_t n)
{
	size_t index;

	index = 0;
	while (index < n)
	{
		*((unsigned char *)dst + index) = *((unsigned char *)src + index);
		if (*((unsigned char *)dst + index) == ((unsigned char)c))
			return (dst + index + 1);
		index++;
	}
	return (NULL);
}
