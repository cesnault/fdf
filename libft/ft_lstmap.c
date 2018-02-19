/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:29:06 by cesnault          #+#    #+#             */
/*   Updated: 2016/11/15 08:26:19 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *tmp;
	t_list *newlst;
	t_list *newelem;

	tmp = lst;
	newlst = NULL;
	if (lst == NULL || (*f) == NULL)
		return (NULL);
	while (tmp)
	{
		newelem = (*f)(tmp);
		ft_lstbackadd(&newlst, newelem);
		tmp = tmp->next;
	}
	return (newlst);
}
