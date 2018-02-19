/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 10:04:58 by cesnault          #+#    #+#             */
/*   Updated: 2016/12/08 09:57:44 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdlib.h"
#include <stdio.h>

void	ft_del(void *content, size_t content_size)
{
	printf("ft_del\n");
	free(content);
	content_size = 0;
	(void)content_size;
}
