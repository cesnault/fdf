/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 09:21:42 by cesnault          #+#    #+#             */
/*   Updated: 2016/11/15 09:22:25 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t length;
	size_t index;

	index = 0;
	length = ft_strlen(dest);
	while (index < n && (src[index] != 0))
	{
		dest[length + index] = src[index];
		index++;
	}
	dest[length + index] = 0;
	return (dest);
}
