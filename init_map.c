/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarabia <jsarabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 14:28:53 by jsarabia          #+#    #+#             */
/*   Updated: 2023/04/06 15:13:03 by jsarabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

int	display_collect(t_map map, t_disp *d)
{
	d->collects.x = 0;
	d->collects.y = 0;
	d->number_collects = num_cols(d->text_map, d);
	d->collects.img = mlx_new_image(d->mlx, 50 * map.cols, 50 * map.rows);
	d->collects.img = mlx_xpm_file_to_image(d->mlx, "images/collect.xpm",
			&d->collects.wid, &d->collects.hei);
	while (d->collects.y < map.rows)
	{
		while (d->text_map[d->collects.y][d->collects.x] != '\0')
		{
			if (d->text_map[d->collects.y][d->collects.x] == 'C')
				mlx_put_image_to_window(d->mlx, d->win, d->collects.img,
					50 * d->collects.x, 50 * d->collects.y);
			d->collects.x++;
		}
		d->collects.x = 0;
		d->collects.y++;
	}
	return (0);
}

int	display_player(t_disp *display)
{
	player_pos(display->text_map, display);
	display->player.img = mlx_new_image(display->mlx, 50, 50);
	display->player.img = mlx_xpm_file_to_image(display->mlx,
			"images/player.xpm", &display->player.wid, &display->player.hei);
	mlx_put_image_to_window(display->mlx, display->win, display->player.img,
		50 * display->player.x, 50 * display->player.y);
	return (0);
}

int	display_walls(t_map map, t_disp d)
{
	t_image	w;

	w.x = 0;
	w.y = 0;
	w.img = mlx_new_image(d.mlx, 50 * map.cols, 50 * map.rows);
	w.img = mlx_xpm_file_to_image(d.mlx, "images/rock_1.xpm", &w.wid, &w.hei);
	while (w.y < map.rows)
	{
		while (d.text_map[w.y][w.x] != '\0')
		{
			if (d.text_map[w.y][w.x] == '1')
				mlx_put_image_to_window(d.mlx, d.win, w.img,
					50 * w.x, 50 * w.y);
			w.x++;
		}
		w.x = 0;
		w.y++;
	}
	return (0);
}

int	display_map(t_map map, t_disp display)
{
	t_image	ground;
	int		x;
	int		y;

	x = 0;
	y = 0;
	ground.img = mlx_new_image(display.mlx, 50 * map.cols, 50 * map.rows);
	ground.img = mlx_xpm_file_to_image(display.mlx, "images/suelito.xpm",
			&ground.wid, &ground.hei);
	while (y < map.rows)
	{
		while (x < map.cols)
		{
			mlx_put_image_to_window(display.mlx, display.win,
				ground.img, 50 * x, 50 * y);
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}
