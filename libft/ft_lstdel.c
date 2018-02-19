/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 16:47:29 by cesnault          #+#    #+#             */
/*   Updated: 2016/11/15 10:25:36 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;

	if (*alst == NULL || (*del) == NULL)
		return ;
	tmp = *alst;
	while (*alst)
	{
		if ((*alst)->next)
			tmp = (*alst)->next;
		else
			tmp = NULL;
		ft_lstdelone(alst, (*del));
		*alst = tmp;
	}
}
