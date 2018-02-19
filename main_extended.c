/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_extended.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 11:47:00 by cesnault          #+#    #+#             */
/*   Updated: 2017/03/16 12:10:46 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx_macos/mlx.h"
#include "wireframe_test.h"
#include <stdlib.h>

void	ft_free_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	ft_size_y(t_fdf *fdf)
{
	int i;
	int j;

	i = 0;
	while (i < fdf->i)
	{
		j = 0;
		while (j < fdf->j)
		{
			if (fdf->height < fdf->map[i][j])
				fdf->height = fdf->map[i][j];
			j++;
		}
		i++;
	}
	j = 0;
	while (j == 0)
	{
		fdf->size_y = fdf->i * fdf->range + fdf->height;
		if (fdf->size_y > SIZEY - 1 && fdf->range != 2)
			fdf->range -= 1;
		else
			j = 1;
	}
}

void	ft_size_x(t_fdf *fdf)
{
	int b;

	b = 0;
	while (b == 0)
	{
		fdf->size_x = fdf->i * fdf->range + fdf->j * fdf->range;
		if ((fdf->size_x > SIZEX - 1) && (fdf->range != 2))
			fdf->range = fdf->range - 1;
		else
			b = 1;
	}
	ft_size_y(fdf);
}
