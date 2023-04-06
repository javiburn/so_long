/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presskey.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarabia <jsarabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 14:44:16 by jsarabia          #+#    #+#             */
/*   Updated: 2023/04/06 14:45:10 by jsarabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

int	game_over(t_disp *display)
{
	mlx_clear_window(display->mlx, display->win);
	mlx_destroy_window(display->mlx, display->win);
	free_matrix(display->text_map);
	exit(0);
	return (0);
}

int	display_floor(t_disp *display, int y, int x)
{
	t_image	floor;

	floor.img = mlx_new_image(display->mlx, 50 * x, 50 * y);
	floor.img = mlx_xpm_file_to_image(display->mlx, "images/suelito.xpm",
			&floor.wid, &floor.hei);
	mlx_put_image_to_window(display->mlx, display->win,
		floor.img, 50 * x, 50 * y);
	return (0);
}

int	display_exit(t_disp *d)
{
	t_image	e;

	e.x = 0;
	e.y = 0;
	e.img = mlx_new_image(d->mlx, 40, 50);
	e.img = mlx_xpm_file_to_image(d->mlx, "images/exit.xpm", &e.wid, &e.hei);
	while (d->text_map[e.y][e.x] != '\0')
	{
		while (d->text_map[e.y][e.x] != '\0')
		{
			if (d->text_map[e.y][e.x] == 'E')
			{
				mlx_put_image_to_window(d->mlx, d->win,
					e.img, 50 * e.x, 50 * e.y);
				return (0);
			}
			e.x++;
		}
		e.x = 0;
		e.y++;
	}
	if (d->text_map[e.y][e.x] != 'E')
		mlx_put_image_to_window(d->mlx, d->win,
			e.img, 50 * d->player.x, 50 * d->player.y);
	return (0);
}

int	movement(int keycode, t_disp *display)
{
	static int	number_movements = 0;
	int			*num;

	num = &number_movements;
	if (keycode == 126 || keycode == 13)
		move_up(display, num);
	if (keycode == 123 || keycode == 0)
		move_left(display, num);
	if (keycode == 124 || keycode == 2)
		move_right(display, num);
	if (keycode == 125 || keycode == 1)
		move_down(display, num);
	if (display->number_collects == 0)
		display_exit(display);
	if (keycode == 53)
		game_over(display);
	return (0);
}
