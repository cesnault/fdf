/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 08:36:57 by cesnault          #+#    #+#             */
/*   Updated: 2016/11/15 10:27:03 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	index;
	int		res;

	res = 0;
	index = 0;
	while (index < n)
	{
		if (*((unsigned char *)s1 + index) != *((unsigned char *)s2 + index))
		{
			res = (int)(*((unsigned char *)s1 + index) -
					*((unsigned char *)s2 + index));
			return (res);
		}
		index++;
	}
	return (0);
}
