/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 09:19:21 by cesnault          #+#    #+#             */
/*   Updated: 2016/11/15 09:20:42 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	index;
	size_t			size;
	char			*res;

	index = 0;
	if (s == (NULL))
		return (NULL);
	size = ft_strlen((char *)s);
	if (!(res = (char *)malloc((sizeof(char) * size) + 1)))
		return (NULL);
	while (s[index])
	{
		res[index] = (*f)(index, s[index]);
		index++;
	}
	res[index] = 0;
	return (res);
}
