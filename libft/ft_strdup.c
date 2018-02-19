/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 16:42:57 by cesnault          #+#    #+#             */
/*   Updated: 2016/11/15 08:59:26 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *src)
{
	int		length;
	char	*res;

	length = 0;
	while (src[length] != 0)
		length++;
	if (!(res = (char*)malloc((sizeof(char) * length) + 1)))
		return (NULL);
	while (length >= 0)
	{
		res[length] = src[length];
		length--;
	}
	return (res);
}
