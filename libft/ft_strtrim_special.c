/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 16:37:49 by cesnault          #+#    #+#             */
/*   Updated: 2016/11/15 10:00:26 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim_special(char const *s, char c)
{
	char	*beg;
	char	*end;
	char	*newstr;
	size_t	index;

	if (s == NULL)
		return (NULL);
	index = 0;
	beg = (char *)s;
	while (*beg == c)
		beg++;
	end = beg;
	while (*end != 0)
		end++;
	while (*(end - 1) == c && (end != beg))
		end--;
	if (!(newstr = (char *)malloc(sizeof(char) *
					ft_strtrim_length(beg, end) + 1)))
		return (NULL);
	while (beg != end)
		newstr[index++] = *(beg++);
	newstr[index] = 0;
	return (newstr);
}
