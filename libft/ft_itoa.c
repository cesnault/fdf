/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 16:53:03 by cesnault          #+#    #+#             */
/*   Updated: 2016/11/14 18:41:25 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static	char	*ft_create_array(char *str, int n, int p)
{
	int		index;
	int		index2;
	char	tab[10];

	index = 0;
	index2 = 0;
	if (p == -1)
		*(str + index++) = '-';
	while (n >= 10 || n <= -10)
	{
		tab[index2++] = '0' + (n % 10) * p;
		n = n / 10;
	}
	tab[index2] = '0' + n * p;
	while (index2 >= 0)
		*(str + index++) = tab[index2--];
	*(str + index) = 0;
	return (str);
}

char			*ft_itoa(int n)
{
	char	*str;
	int		p;
	int		nb_length;

	p = 1;
	nb_length = ft_number_length(n);
	if (n < 0)
	{
		if (!(str = (char *)malloc(sizeof(char) * (nb_length + 1) + 1)))
			return (NULL);
		p = -1;
	}
	else if (!(str = (char *)malloc(sizeof(char) * nb_length + 1)))
		return (NULL);
	return (ft_create_array(str, n, p));
}
