/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 16:13:27 by cesnault          #+#    #+#             */
/*   Updated: 2016/11/15 08:48:57 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	int tab[10];
	int index;

	index = 0;
	if (n < 0)
		ft_putchar('-');
	while (n >= 10 || n <= -10)
	{
		tab[index] = (n % 10);
		n = n / 10;
		index++;
	}
	tab[index] = n;
	while (index >= 0)
	{
		if (n >= 0)
			ft_putchar('0' + tab[index]);
		else
			ft_putchar('0' + (tab[index] * -1));
		index--;
	}
}
