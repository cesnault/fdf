/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 09:28:03 by cesnault          #+#    #+#             */
/*   Updated: 2016/11/15 09:29:27 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t index;

	if (s1 == NULL || s2 == NULL)
		return (0);
	index = 0;
	while ((s1[index] != 0) && (s2[index] != 0) && (index < n))
	{
		if (s1[index] != s2[index])
			return (0);
		index++;
	}
	if (((s1[index] == 0) && (s2[index] == 0)) || (index == n))
		return (1);
	return (0);
}
