/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 09:17:06 by cesnault          #+#    #+#             */
/*   Updated: 2016/11/15 09:18:39 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	index;
	size_t	size;
	char	*res;

	index = 0;
	if (s == NULL)
		return (NULL);
	size = ft_strlen((char *)s);
	if (!(res = (char *)malloc((sizeof(char) * size) + 1)))
		return (NULL);
	while (s[index])
	{
		res[index] = (*f)(s[index]);
		index++;
	}
	res[index] = 0;
	return (res);
}
