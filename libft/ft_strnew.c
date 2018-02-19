/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 09:30:15 by cesnault          #+#    #+#             */
/*   Updated: 2016/11/15 09:31:15 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*str;
	size_t	index;

	index = 0;
	if (!(str = (char *)malloc((sizeof(char) * size) + 1)))
		return (NULL);
	while (index < size + 1)
	{
		str[index] = 0;
		index++;
	}
	return (str);
}
