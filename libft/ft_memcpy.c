/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 16:15:05 by cesnault          #+#    #+#             */
/*   Updated: 2016/11/14 16:21:31 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	size_t index;

	index = 0;
	while (index < n)
	{
		*((unsigned char *)dst + index) = *((unsigned char *)src + index);
		index++;
	}
	return (dst);
}
