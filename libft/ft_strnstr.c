/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 09:31:49 by cesnault          #+#    #+#             */
/*   Updated: 2016/11/15 10:35:33 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	begin;
	size_t	p;

	begin = 0;
	i = 0;
	p = 0;
	if (*(s1) == 0 && (*(s1) == *(s2)))
		return (char *)s1;
	while (*(s1 + i) && i < n)
	{
		begin = i;
		while (*(s1 + i) && *(s2 + p) && (*(s1 + i) == *(s2 + p)) && i < n)
		{
			i++;
			p++;
		}
		if (((p == n) || (p == ft_strlen((char *)s2))) && (*(s2 + p) == 0))
			return (char *)(s1 + begin);
		if (i >= n)
			return (NULL);
		i = begin + 1;
		p = 0;
	}
	return (NULL);
}
