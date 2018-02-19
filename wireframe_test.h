/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wireframe_test.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 16:43:21 by cesnault          #+#    #+#             */
/*   Updated: 2017/03/16 15:20:39 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WIREFRAME_TEST_H
# define WIREFRAME_TEST_H
# define SIZEX 2560
# define SIZEY 1440
# define WHITE 0x00FFFFFF

typedef struct	s_fdf
{
	void	*mlx;
	void	*win;
	void	*image;
	int		c1;
	int		c2;
	int		c3;
	int		range;
	int		i;
	int		j;
	int		**map;
	int		size_x;
	int		size_y;
	int		height;
}				t_fdf;

typedef	struct	s_coord
{
	int x;
	int y;
	int h;
	int nextline_y;
	int nextline_x;
}				t_coord;

typedef struct	s_wireframe
{
	t_coord beg;
	t_coord end;
	int		error_x;
	int		error_y;
	int		div_x;
	int		div_y;
	int		incr_x;
	int		incr_y;
}				t_wireframe;

int				draw_line(t_coord beg, t_coord end, t_fdf *fdf);
void			ft_draw(t_fdf *fdf);
void			ft_iso(t_fdf *fdf);
void			ft_feed(t_fdf fdf, int fd);
void			ft_size_x(t_fdf *fdf);
void			ft_size_y(t_fdf *fdf);
void			ft_feed_tab(t_fdf fdf, int fd);
void			ft_free_tab(char **tab);
int				red_cross(int key, t_fdf *fdf);
#endif
