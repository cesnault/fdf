/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 08:35:24 by cesnault          #+#    #+#             */
/*   Updated: 2017/03/16 15:03:33 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "minilibx_macos/mlx.h"
#include "wireframe_test.h"
#include <stdlib.h>
#include <unistd.h>
#include "libft/includes/libft.h"
#include "libft/includes/get_next_line.h"

void	ft_feed_tab(t_fdf fdf, int fd)
{
	char	*str;
	char	**tab;
	int		j;
	int		i;

	i = 0;
	while ((get_next_line(fd, &str) != 0) && i < fdf.i)
	{
		tab = ft_strsplit(str, ' ');
		j = 0;
		while (tab[j] != 0 && j < fdf.j)
		{
			fdf.map[i][j] = ft_atoi(tab[j]);
			j++;
		}
		ft_free_tab(tab);
		i++;
		free(str);
	}
	fdf.mlx = mlx_init();
	fdf.range = 20;
	ft_size_x(&fdf);
	fdf.win = mlx_new_window(fdf.mlx, SIZEX, SIZEY, "map");
	ft_draw(&fdf);
}

void	ft_create_tab(t_fdf fdf, char *ag)
{
	int i;
	int j;
	int fd;

	fdf.map = (int**)malloc(sizeof(int *) * fdf.i);
	i = 0;
	while (i < fdf.i)
		fdf.map[i++] = (int *)malloc(sizeof(int) * fdf.j);
	i = 0;
	while (i < fdf.i)
	{
		j = 0;
		while (j < fdf.j)
		{
			fdf.map[i][j] = 0;
			j++;
		}
		i++;
	}
	if ((fd = open(ag, O_RDONLY)) == -1)
		return ;
	i = 0;
	ft_feed_tab(fdf, fd);
}

void	ft_check(t_fdf *fdf, int fd, int j)
{
	int		i;
	int		res;
	char	*str;

	i = 0;
	while (get_next_line(fd, &str) > 0)
	{
		j = 0;
		res = 0;
		while (str[j] != 0)
		{
			if ((str[j] > 47 && str[j] < 58 &&
						(str[j + 1] == ' ' || str[j + 1] == 0)))
				res++;
			j++;
		}
		if (i == 0)
			fdf->j = res;
		else if (fdf->j < res)
			fdf->j = res;
		i++;
		free(str);
	}
	fdf->i = i;
	close(fd);
}

void	ft_palette(t_fdf *fdf)
{
	fdf->c1 = 0x0089725B;
	fdf->c2 = 0x00B7CA79;
	fdf->c3 = 0x00677e52;
}

int		main(int ac, char **ag)
{
	int		fd;
	t_fdf	fdf;
	int		j;

	j = 0;
	fdf.j = 0;
	fdf.i = 0;
	fdf.image = NULL;
	ft_palette(&fdf);
	if (ac > 2)
		return (1);
	if ((fd = open(ag[1], O_RDONLY)) == -1)
		return (1);
	ft_check(&fdf, fd, j);
	ft_create_tab(fdf, ag[1]);
	return (0);
}
