/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_length.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 14:23:29 by cesnault          #+#    #+#             */
/*   Updated: 2016/11/15 09:58:26 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t		ft_strtrim_length(char *s1, char *s2)
{
	size_t length;

	length = 0;
	while (s1 != (s2))
	{
		length++;
		s1++;
	}
	return (length);
}
