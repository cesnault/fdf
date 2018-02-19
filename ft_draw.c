/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 14:46:25 by cesnault          #+#    #+#             */
/*   Updated: 2017/03/16 12:31:10 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wireframe_test.h"
#include "minilibx_macos/mlx.h"
#include <stdlib.h>

void	another_color(t_fdf *param)
{
	param->c1 = 0x00F30109;
	param->c2 = 0x00D50101;
	param->c3 = 0x00AE0000;
}

int		key_funct(int keycode, void *param)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 15)
		another_color(((t_fdf *)param));
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
		ft_iso((t_fdf *)param);
	else
		ft_draw((t_fdf *)param);
	return (0);
}

void	ft_draw_verti(t_fdf *fdf, t_coord *beg, t_coord *end, int index)
{
	int jndex;

	jndex = 0;
	while (jndex < fdf->j)
	{
		index = 0;
		while (index + 1 < fdf->i)
		{
			beg->h = fdf->map[index][jndex];
			end->h = fdf->map[index + 1][jndex];
			draw_line(*beg, *end, fdf);
			beg->x = end->x;
			beg->y = end->y;
			beg->h = end->h;
			end->x -= fdf->range;
			end->y += fdf->range;
			index++;
		}
		beg->x = beg->nextline_x;
		beg->y = beg->nextline_y;
		beg->nextline_x += fdf->range;
		end->x = beg->x - fdf->range;
		end->y = beg->y + fdf->range;
		jndex++;
	}
}

void	ft_draw_hori(t_fdf *fdf, t_coord *beg, t_coord *end)
{
	int index;
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
			jndex++;
		}
		beg->x = beg->nextline_x;
		beg->y = beg->nextline_y;
		beg->nextline_y += fdf->range;
		beg->nextline_x -= fdf->range;
		end->x = beg->x + fdf->range;
		end->y = beg->y;
		index++;
	}
}

void	ft_draw(t_fdf *fdf)
{
	t_coord	beg;
	t_coord	end;
	int		index;

	index = 0;
	beg.x = SIZEX / 2 - ((fdf->j * fdf->range)
			/ 2) + ((fdf->i * fdf->range) / 2);
	beg.y = SIZEY / 2 - ((fdf->i * fdf->range) / 2);
	beg.nextline_y = beg.y + fdf->range;
	beg.nextline_x = beg.x - fdf->range;
	end.x = beg.x + fdf->range;
	end.y = beg.y;
	ft_draw_hori(fdf, &beg, &end);
	beg.x = SIZEX / 2 - ((fdf->j * fdf->range)
			/ 2) + ((fdf->i * fdf->range) / 2);
	beg.y = SIZEY / 2 - ((fdf->i * fdf->range) / 2);
	beg.nextline_y = beg.y;
	beg.nextline_x = beg.x + fdf->range;
	end.x = beg.x - fdf->range;
	end.y = beg.y + fdf->range;
	ft_draw_verti(fdf, &beg, &end, index);
	mlx_key_hook(fdf->win, key_funct, fdf);
	mlx_hook(fdf->win, 17, 1L << 17, red_cross, fdf);
	mlx_loop(fdf->mlx);
}
