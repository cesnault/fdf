/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 09:37:39 by cesnault          #+#    #+#             */
/*   Updated: 2016/11/15 09:40:03 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		index;
	char	*res;

	index = ft_strlen((char *)s);
	res = (char *)s;
	while (index >= 0)
	{
		if (s[index] == c)
			return (res + index);
		index--;
	}
	return (0);
}
