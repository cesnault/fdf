/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 18:14:19 by cesnault          #+#    #+#             */
/*   Updated: 2016/11/15 09:25:25 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_strncmp(const char *s1, const char *s2, size_t len)
{
	size_t index;

	index = 0;
	while (*s1 != 0 && *s2 != 0 && (index < len))
	{
		if (*((unsigned char *)s1) != *((unsigned char *)s2))
			return (*((unsigned char *)s1) - *((unsigned char *)s2));
		s1++;
		s2++;
		index++;
	}
	if (index < len)
		return (*((unsigned char*)s1) - *((unsigned char *)s2));
	return (0);
}
