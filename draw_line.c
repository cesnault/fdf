/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 13:05:30 by cesnault          #+#    #+#             */
/*   Updated: 2017/03/16 15:25:11 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wireframe_test.h"
#include <stdlib.h>
#include "minilibx_macos/mlx.h"
#include <math.h>

void	ft_verti(t_coord beg, t_coord end, t_wireframe wire, t_fdf *fdf)
{
	int i;

	i = 0;
	while (i <= wire.div_y)
	{
		if (((((double)end.h / fdf->height * 100) < 33) && (((double)end.h
						/ fdf->height * 100) < 33)) && (end.h > 1 || beg.h > 1))
			mlx_pixel_put(fdf->mlx, fdf->win, wire.beg.x, wire.beg.y, fdf->c3);
		else if ((((double)end.h / fdf->height * 100) < 66) && (((double)end.h
						/ fdf->height * 100) < 66) && (end.h > 1 || beg.h > 1))
			mlx_pixel_put(fdf->mlx, fdf->win, wire.beg.x, wire.beg.y, fdf->c2);
		else if (end.h > 1 || beg.h > 1)
			mlx_pixel_put(fdf->mlx, fdf->win, wire.beg.x, wire.beg.y, fdf->c1);
		else
			mlx_pixel_put(fdf->mlx, fdf->win, wire.beg.x, wire.beg.y, WHITE);
		i++;
		wire.beg.y += wire.incr_y;
		wire.error_y -= (wire.div_x * 2);
		if (wire.error_y < 0)
		{
			wire.beg.x += wire.incr_x;
			wire.error_y += (wire.div_y * 2);
		}
	}
}

void	ft_hori(t_coord beg, t_coord end, t_wireframe wire, t_fdf *fdf)
{
	int i;

	i = 0;
	while (i <= wire.div_x)
	{
		if (((((double)end.h / fdf->height * 100) < 33) && (((double)end.h
						/ fdf->height * 100) < 33)) && (end.h > 1 || beg.h > 1))
			mlx_pixel_put(fdf->mlx, fdf->win, wire.beg.x, wire.beg.y, fdf->c3);
		else if ((((double)end.h / fdf->height * 100) < 66) && (((double)end.h
					/ fdf->height * 100) < 66) && (end.h > 1 || beg.h > 1))
			mlx_pixel_put(fdf->mlx, fdf->win, wire.beg.x, wire.beg.y, fdf->c2);
		else if (end.h > 1 || beg.h > 1)
			mlx_pixel_put(fdf->mlx, fdf->win, wire.beg.x, wire.beg.y, fdf->c1);
		else
			mlx_pixel_put(fdf->mlx, fdf->win, wire.beg.x, wire.beg.y, WHITE);
		i++;
		wire.beg.x += wire.incr_x;
		wire.error_x -= (wire.div_y * 2);
		if (wire.error_x < 0)
		{
			wire.beg.y += wire.incr_y;
			wire.error_x += (wire.div_x * 2);
		}
	}
}

int		draw_line(t_coord beg, t_coord end, t_fdf *fdf)
{
	t_wireframe wire;

	end.y -= end.h;
	beg.y -= beg.h;
	wire.error_x = abs(end.x - beg.x);
	wire.error_y = abs(end.y - beg.y);
	wire.div_x = wire.error_x;
	wire.div_y = wire.error_y;
	wire.incr_x = 1;
	wire.incr_y = 1;
	wire.beg = beg;
	wire.end = end;
	if (wire.beg.x > wire.end.x)
		wire.incr_x = -1;
	if (wire.beg.y > wire.end.y)
		wire.incr_y = -1;
	if (wire.div_x >= wire.div_y)
	{
		ft_hori(beg, end, wire, fdf);
	}
	else if (wire.div_x < wire.div_y)
	{
		ft_verti(beg, end, wire, fdf);
	}
	return (0);
}
