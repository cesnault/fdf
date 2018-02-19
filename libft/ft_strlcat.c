/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 08:27:03 by cesnault          #+#    #+#             */
/*   Updated: 2016/11/15 09:15:43 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t size)
{
	size_t		lendst;
	size_t		i;
	size_t		lensrc;

	i = 0;
	lendst = ft_strlen((char *)dst);
	lensrc = ft_strlen((char *)src);
	if (size < lendst)
		return (size + lensrc);
	while (*(src) != 0 && ((lendst + i) < (size - 1)))
	{
		*(dst + lendst + i) = *(src + i);
		i++;
	}
	*(dst + lendst + i) = 0;
	return (lendst + lensrc);
}
