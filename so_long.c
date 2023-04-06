/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarabia <jsarabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 14:38:52 by jsarabia          #+#    #+#             */
/*   Updated: 2023/04/06 15:05:32 by jsarabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

int	main(int argc, char **argv)
{
	t_disp	display;
	t_map	map;

	display.char_readed = '0';
	map = ft_map_coord(argv[1]);
	display.text_map = ft_text_map(argv[1], map);
	player_pos(display.text_map, &display);
	if (!check_map(argc, map, argv[1], &display))
	{
		free_all(&display);
		return (0);
	}
	display.mlx = mlx_init();
	display.win = mlx_new_window(display.mlx,
			50 * map.cols, 50 * map.rows, "so_long");
	display_map(map, display);
	display_walls(map, display);
	display_player(&display);
	display.number_collects = num_cols(display.text_map, &display);
	display_collect(map, &display);
	mlx_hook(display.win, 2, 1L << 0, movement, &display);
	mlx_hook(display.win, 17, 0, game_over, &display);
	mlx_loop(display.mlx);
	exit(0);
	return (0);
}
