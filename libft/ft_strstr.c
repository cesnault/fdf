/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 09:45:01 by cesnault          #+#    #+#             */
/*   Updated: 2016/11/15 10:32:27 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t	i;
	size_t	begin;
	size_t	p;

	begin = 0;
	i = 0;
	p = 0;
	if (*(s1) == 0 && (*(s1) == *(s2)))
		return (char *)s1;
	while (*(s1 + i))
	{
		begin = i;
		while (*(s1 + i) && *(s2 + p) && (*(s1 + i) == *(s2 + p)))
		{
			i++;
			p++;
		}
		if (*(s2 + p) == 0)
			return (char *)(s1 + begin);
		i = begin + 1;
		p = 0;
	}
	return (NULL);
}
