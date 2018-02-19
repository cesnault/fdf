/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 08:59:54 by cesnault          #+#    #+#             */
/*   Updated: 2016/11/15 09:03:12 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strequ(char const *s1, char const *s2)
{
	unsigned long index;

	if (s1 == 0 || s2 == 0)
		return (0);
	index = 0;
	while ((s1[index] != 0) && (s2[index] != 0))
	{
		if (s1[index] != s2[index])
			return (0);
		index++;
	}
	if ((s1[index] == 0) && (s2[index] == 0))
		return (1);
	return (0);
}
