/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 16:24:06 by cesnault          #+#    #+#             */
/*   Updated: 2016/11/15 10:25:19 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	printf("debut\n");
	if (*alst == NULL || (*del) == NULL)
		return ;
	printf("del\n");
	(*del)((*alst)->content, (*alst)->content_size);
	printf("free\n");
	free(*alst);
	*alst = NULL;
}
