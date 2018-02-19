/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 14:44:56 by cesnault          #+#    #+#             */
/*   Updated: 2016/11/15 10:37:37 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static	char		*ft_word(char **beg, char c)
{
	size_t	index;
	char	*str;
	size_t	length;

	length = 0;
	index = 0;
	while (*(*beg + length) != c && *(*beg + length) != 0)
	{
		length++;
	}
	str = (char *)malloc(sizeof(char) * length + 1);
	while (index < length)
	{
		str[index++] = **beg;
		(*beg)++;
	}
	str[index] = 0;
	return (str);
}

static	size_t		ft_nbwords(char const *s, char c)
{
	size_t index;
	size_t nb_word;

	index = 0;
	nb_word = 0;
	while (s[index])
	{
		if (s[index] != c && (s[index + 1] == c || s[index + 1] == 0))
			nb_word++;
		index++;
	}
	return (nb_word);
}

char				**ft_strsplit(char const *s, char c)
{
	char	*src;
	char	*beg;
	char	**tab;
	size_t	length;
	size_t	index;

	if (s == NULL)
		return (NULL);
	index = 0;
	src = ft_strtrim_special(s, c);
	beg = src;
	length = ft_nbwords(s, c);
	if (!(tab = (char **)malloc(sizeof(char *) * length + 1)))
		return (NULL);
	while (*beg != 0)
	{
		if (*beg != c)
			tab[index++] = ft_word(&beg, c);
		while (*beg == c)
			beg++;
	}
	tab[index] = 0;
	return (tab);
}
