/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 12:41:40 by cesnault          #+#    #+#             */
/*   Updated: 2016/11/15 08:51:04 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *restrict s1, const char *restrict s2)
{
	int index;
	int j;

	index = 0;
	j = 0;
	while (s1[index] != 0)
		index++;
	while (s2[j] != 0)
	{
		s1[index] = s2[j];
		index++;
		j++;
	}
	s1[index] = 0;
	return (s1);
}
