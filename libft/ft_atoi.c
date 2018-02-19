/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 17:30:24 by cesnault          #+#    #+#             */
/*   Updated: 2016/11/15 10:08:44 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int res;
	int val;

	res = 0;
	val = 1;
	while ((*str == ' ' || *str == '\t' || *str == '\v' || *str == '\f'
				|| *str == '\r' || *str == '\n') && *str != 0)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			val = -1;
		str++;
	}
	if (*str == 0)
		return (0);
	while (*str > 47 && *str < 58)
	{
		res = res * 10;
		res = (res + (*str - 48));
		str++;
	}
	return (res * val);
}
