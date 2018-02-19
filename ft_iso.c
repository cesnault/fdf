/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iso.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 16:14:51 by cesnault          #+#    #+#             */
/*   Updated: 2017/03/16 12:31:57 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wireframe_test.h"
#include "minilibx_macos/mlx.h"
#include <stdlib.h>

void	yet_another_color(t_fdf *param)
{
	((t_fdf *)param)->c1 = 0x00F30109;
	((t_fdf *)param)->c2 = 0x00D50101;
	((t_fdf *)param)->c3 = 0x00AE0000;
}

int		keys_funct(int keycode, void *param)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 15)
		yet_another_color(((t_fdf *)param));
	if (keycode == 11)
	{
		((t_fdf *)param)->c1 = 0x005761F4;
		((t_fdf *)param)->c2 = 0x003844F0;
		((t_fdf *)param)->c3 = 0x001A28ED;
	}
	if (keycode == 9)
	{
		((t_fdf *)param)->c1 = 0x0048FE11;
		((t_fdf *)param)->c2 = 0x002A8C0C;
		((t_fdf *)param)->c3 = 0x00154606;
	}
	mlx_clear_window(((t_fdf *)param)->mlx, ((t_fdf *)param)->win);
	if (keycode == 125)
		ft_draw((t_fdf *)param);
	else
		ft_iso((t_fdf *)param);
	return (0);
}

void	ft_iso_left(t_fdf *fdf, t_coord *beg, t_coord *end, int val[2])
{
	val[1] = 0;
	while (val[1] < fdf->j)
	{
		val[0] = 0;
		while (val[0] + 1 < fdf->i)
		{
			beg->h = fdf->map[val[0]][val[1]];
			end->h = fdf->map[val[0] + 1][val[1]];
			draw_line(*beg, *end, fdf);
			beg->x = end->x;
			beg->y = end->y;
			beg->h = end->h;
			end->x -= fdf->range;
			end->y += (fdf->range / 2);
			val[0]++;
		}
		beg->x = beg->nextline_x;
		beg->y = beg->nextline_y;
		beg->nextline_x += fdf->range;
		beg->nextline_y += (fdf->range / 2);
		end->x = beg->x - fdf->range;
		end->y = beg->y + (fdf->range / 2);
		val[1]++;
	}
}

void	ft_iso_right(t_fdf *fdf, t_coord *beg, t_coord *end, int index)
{
	int jndex;

	index = 0;
	while (index < fdf->i)
	{
		jndex = 0;
		while (jndex + 1 < fdf->j)
		{
			beg->h = fdf->map[index][jndex];
			end->h = fdf->map[index][jndex + 1];
			draw_line(*beg, *end, fdf);
			beg->x = end->x;
			beg->y = end->y;
			end->x += fdf->range;
			end->y += (fdf->range / 2);
			jndex++;
		}
		beg->x = beg->nextline_x;
		beg->y = beg->nextline_y;
		beg->nextline_y += (fdf->range / 2);
		beg->nextline_x -= fdf->range;
		end->x = beg->x + fdf->range;
		end->y = beg->y + (fdf->range / 2);
		index++;
	}
}

void	ft_iso(t_fdf *fdf)
{
	t_coord	beg;
	t_coord	end;
	int		index;
	int		val[2];

	index = 0;
	beg.x = SIZEX / 2 + ((fdf->i * fdf->range)
			/ 2) - ((fdf->j * fdf->range) / 2);
	beg.y = SIZEY / 2 - ((fdf->i * fdf->range) / 2);
	beg.nextline_y = beg.y + (fdf->range / 2);
	beg.nextline_x = beg.x - fdf->range;
	end.x = beg.x + fdf->range;
	end.y = beg.y + (fdf->range / 2);
	ft_iso_right(fdf, &beg, &end, index);
	beg.x = SIZEX / 2 + ((fdf->i * fdf->range)
			/ 2) - ((fdf->j * fdf->range) / 2);
	beg.y = SIZEY / 2 - ((fdf->i * fdf->range) / 2);
	beg.nextline_y = beg.y + (fdf->range / 2);
	beg.nextline_x = beg.x + fdf->range;
	end.x = beg.x - fdf->range;
	end.y = beg.y + (fdf->range / 2);
	ft_iso_left(fdf, &beg, &end, &val[2]);
	mlx_key_hook(fdf->win, keys_funct, fdf);
	mlx_hook(fdf->win, 17, (1L << 17), red_cross, fdf);
	mlx_loop(fdf->mlx);
}
