/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarabia <jsarabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:10:45 by jsarabia          #+#    #+#             */
/*   Updated: 2023/04/06 14:23:59 by jsarabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

static int	check_weird_char(char **text_map, int y)
{
	int	x;
	int	ret;

	x = 0;
	ret = 0;
	while (text_map[y][x] != '\0')
	{
		if (text_map[y][x] == '0' || text_map[y][x] == '1')
			ret = 1;
		else if (text_map[y][x] == 'P' || text_map[y][x] == 'C')
			ret = 1;
		else if (text_map[y][x] == 'E' || text_map[y][x] == '\n')
			ret = 1;
		else
			return (0);
		x++;
	}
	return (ret);
}

static int	check_exits(char **text_map)
{
	int	x;
	int	y;
	int	number_exits;

	x = 0;
	y = 0;
	number_exits = 0;
	while (text_map[y] != '\0')
	{
		while (text_map[y][x] != '\0')
		{
			if (text_map[y][x] == 'E')
				number_exits++;
			x++;
		}
		x = 0;
		y++;
	}
	if (number_exits != 1)
		return (0);
	return (1);
}

static int	check_walls(char **text_map, int y, t_map map)
{
	int	x;

	x = 0;
	if (y == 0 || y == map.rows - 1)
	{
		while (text_map[y][x] != '\0')
		{
			if (text_map[y][x] == '1')
				x++;
			if (x == (int)ft_strlen(text_map[y]) - 1 && text_map[y][x] == '\n')
				return (1);
			else if (text_map[y][x] != '1' && text_map[y][x] != '\n')
				return (0);
		}
	}
	else
	{
		if (text_map[y][0] == '1' && text_map[y][map.cols - 1] == '1')
			return (1);
		else
			return (0);
	}
	return (1);
}

static int	some_checks(int argc, char **text_map, char *argv, t_map map)
{
	char	**newmap;

	if (argc != 2)
		return (print_error(1));
	if (!text_map)
		return (print_error(2));
	newmap = ft_text_map(argv, map);
	if (!check_way(newmap, map))
		return (print_error(10));
	return (1);
}

int	check_map(int argc, t_map map, char *argv, t_disp *display)
{
	int		y;

	if (!some_checks(argc, display->text_map, argv, map))
		return (0);
	y = 0;
	if (!check_exits(display->text_map))
		return (print_error(6));
	if (!num_cols(display->text_map, display))
		return (print_error(9));
	if (!player_pos(display->text_map, display))
		return (print_error(5));
	if (!check_ber(argv))
		return (print_error(8));
	while (y < map.rows)
	{
		if (!check_walls(display->text_map, y, map))
			return (print_error(3));
		if ((int)ft_strlen(display->text_map[y]) != map.cols + 1)
			return (print_error(4));
		if (!check_weird_char(display->text_map, y))
			return (print_error(7));
		y++;
	}
	return (1);
}
