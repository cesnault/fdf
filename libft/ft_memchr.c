/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 17:18:52 by cesnault          #+#    #+#             */
/*   Updated: 2016/11/15 10:27:33 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			index;
	unsigned char	*res;

	index = 0;
	while (index < n)
	{
		res = ((unsigned char *)s + index);
		if (*((unsigned char *)s + index) == ((unsigned char)c))
			return (res);
		index++;
	}
	return (NULL);
}
