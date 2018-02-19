/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 08:53:59 by cesnault          #+#    #+#             */
/*   Updated: 2016/11/15 10:36:46 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strclr(char *s)
{
	size_t	size;
	size_t	index;

	if (s == 0)
		return ;
	index = 0;
	size = ft_strlen(s);
	while (index < size)
	{
		s[index] = 0;
		index++;
	}
}
