/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 09:03:49 by cesnault          #+#    #+#             */
/*   Updated: 2016/11/15 09:05:55 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striter(char *s, void (*f)(char *))
{
	unsigned long index;

	index = 0;
	if (s == 0 || f == 0)
		return ;
	while (s[index])
	{
		(*f)(s + index);
		index++;
	}
}
