/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarabia <jsarabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 13:25:38 by jsarabia          #+#    #+#             */
/*   Updated: 2023/04/10 12:49:33 by jsarabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>
# include "get_next_line_bonus.h"
# include "ft_printf.h"
# include "libft.h"

typedef struct images
{
	void	*img;
	int		wid;
	int		hei;
	int		x;
	int		y;
}	t_image;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_disp
{
	void	*mlx;
	void	*win;
	t_image	player;
	t_image	collects;
	t_image	ext;
	char	**text_map;
	int		number_collects;
	char	char_readed;
}	t_disp;

typedef struct map_size
{
	int	cols;
	int	rows;
}	t_map;

int		num_cols(char **map, t_disp *display);
t_map	ft_map_coord(char *argv);
char	**ft_text_map(char *argv, t_map map);
int		check_map(int argc, t_map map, char *argv, t_disp *display);
int		player_pos(char **map, t_disp *d);
int		print_error(int error);
void	free_all(t_disp *display);
int		check_way(char **text_map, t_map map);
void	free_matrix(char **matrix);
int		check_ber(char *argv);
int		display_collect(t_map map, t_disp *d);
int		display_player(t_disp *display);
int		display_walls(t_map map, t_disp d);
int		display_map(t_map map, t_disp display);
int		game_over(t_disp *display);
int		display_floor(t_disp *display, int y, int x);
int		display_exit(t_disp *d);
int		movement(int keycode, t_disp *display);
int		move_up(t_disp *display, int *num);
int		move_right(t_disp *display, int *num);
int		move_left(t_disp *display, int *num);
int		move_down(t_disp *display, int *num);
int		check_squareness(char **text_map);

#endif
