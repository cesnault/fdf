/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 16:37:49 by cesnault          #+#    #+#             */
/*   Updated: 2016/11/15 09:57:38 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s)
{
	char	*beg;
	char	*end;
	char	*newstr;
	size_t	index;

	if (s == NULL)
		return (NULL);
	index = 0;
	beg = (char *)s;
	while (*beg == ' ' || *beg == '\t' || *beg == '\n')
		beg++;
	end = beg;
	while (*end != 0)
		end++;
	while ((*(end - 1) == ' ' || *(end - 1) == '\t' ||
				*(end - 1) == '\n') && (end != beg))
		end--;
	if (!(newstr = (char *)malloc(sizeof(char) *
					ft_strtrim_length(beg, end) + 1)))
		return (NULL);
	while (beg != end)
		newstr[index++] = *(beg++);
	newstr[index] = 0;
	return (newstr);
}
