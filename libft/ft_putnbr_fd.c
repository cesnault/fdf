/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 16:45:50 by cesnault          #+#    #+#             */
/*   Updated: 2016/11/15 08:49:36 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int tab[10];
	int index;

	index = 0;
	if (n < 0)
		ft_putchar_fd('-', fd);
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
			ft_putchar_fd('0' + tab[index], fd);
		else
			ft_putchar_fd('0' + (tab[index] * -1), fd);
		index--;
	}
}
