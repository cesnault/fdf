/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 11:32:11 by cesnault          #+#    #+#             */
/*   Updated: 2016/11/15 09:13:06 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		size;
	size_t		index;
	size_t		index2;
	char		*str;

	if (s1 == NULL || s2 == NULL)
		return (0);
	index = 0;
	index2 = 0;
	size = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	if (!(str = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	while (s1[index])
	{
		str[index] = s1[index];
		index++;
	}
	while (s2[index2])
	{
		str[index] = s2[index2];
		index++;
		index2++;
	}
	str[index] = 0;
	return (str);
}
