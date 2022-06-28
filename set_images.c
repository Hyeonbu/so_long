/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanjeon <chanjeon@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 02:04:07 by chanjeon          #+#    #+#             */
/*   Updated: 2022/06/29 07:49:53 by chanjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_image	image_initial(void *mlx)
{
	t_image	img;
	int		wid;
	int		hei;

	img.land = mlx_xpm_file_to_image(mlx, "./images/land.xpm", &wid, &hei);
	img.chr = mlx_xpm_file_to_image(mlx, "./images/chr.xpm", &wid, &hei);
	img.star = mlx_xpm_file_to_image(mlx, "./images/star.xpm", &wid, &hei);
	img.close = mlx_xpm_file_to_image(mlx, "./images/close.xpm", &wid, &hei);
	img.open = mlx_xpm_file_to_image(mlx, "./images/open.xpm", &wid, &hei);
	img.wall = mlx_xpm_file_to_image(mlx, "./images/wall.xpm", &wid, &hei);
	return (img);
}

void	put_image(t_system *s, int w, int h)
{
	if (s->line[h * s->width + w] == '1')
		mlx_put_image_to_window(s->mlx, s->win, s->image.wall, w * 64, h * 64);
	else if (s->line[h * s->width + w] == 'C')
		mlx_put_image_to_window(s->mlx, s->win, s->image.star, w * 64, h * 64);
	else if (s->line[h * s->width + w] == 'P')
		mlx_put_image_to_window(s->mlx, s->win, s->image.chr, w * 64, h * 64);
	else if (s->line[h * s->width + w] == 'E' && s->col_num == s->col_cnt)
		mlx_put_image_to_window(s->mlx, s->win, s->image.open, w * 64, h * 64);
	else if (s->line[h * s->width + w] == 'E')
		mlx_put_image_to_window(s->mlx, s->win, s->image.close, w * 64, h * 64);
	else
		mlx_put_image_to_window(s->mlx, s->win, s->image.land, w * 64, h * 64);
}

void	set_images(t_system *sys)
{
	int	width;
	int	height;

	height = 0;
	while (height < sys->height)
	{
		width = 0;
		while (width < sys->width)
		{
			put_image(sys, width, height);
			width++;
		}
		height++;
	}
}
