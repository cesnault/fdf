/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 09:06:26 by cesnault          #+#    #+#             */
/*   Updated: 2016/11/15 10:37:16 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int index;

	if (s == NULL || f == NULL)
		return ;
	index = 0;
	while (s[index])
	{
		(*f)(index, s + index);
		index++;
	}
}
