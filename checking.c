/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarabia <jsarabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 16:04:13 by jsarabia          #+#    #+#             */
/*   Updated: 2023/04/10 12:51:55 by jsarabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

int	check_ber(char *argv)
{
	int	n;

	n = (int)ft_strlen(argv);
	if (argv[n - 1] != 'r')
		return (0);
	if (argv[n - 2] != 'e')
		return (0);
	if (argv[n - 3] != 'b')
		return (0);
	if (argv[n - 4] != '.')
		return (0);
	return (1);
}

int	check_squareness(char **text_map)
{
	int	y;
	int	len;

	y = 0;
	len = (int)ft_strlen(text_map[y]);
	while (text_map[y] != '\0')
	{
		if ((int)ft_strlen(text_map[y]) != len)
			return (0);
		y++;
	}
	return (1);
}

t_map	pos_play(char **text_map)
{
	t_map	pos;

	pos.rows = 0;
	pos.cols = 0;
	while (text_map[pos.rows] != '\0')
	{
		while (text_map[pos.rows][pos.cols] != '\0')
		{
			if (text_map[pos.rows][pos.cols] == 'P')
				return (pos);
			pos.cols++;
		}
		pos.cols = 0;
		pos.rows++;
	}
	pos.cols = -1;
	return (pos);
}

void	fill(char **text_map, t_map pos, t_map map)
{
	if (pos.cols < 0 || pos.cols >= map.cols || pos.rows < 0
		|| pos.rows >= map.rows || (text_map[pos.rows][pos.cols] != 'E'
		&& text_map[pos.rows][pos.cols] != '0' &&
		text_map[pos.rows][pos.cols] != 'C' &&
		text_map[pos.rows][pos.cols] != 'P'))
		return ;
	text_map[pos.rows][pos.cols] = 'F';
	fill(text_map, (t_map){pos.cols, pos.rows - 1}, map);
	fill(text_map, (t_map){pos.cols + 1, pos.rows}, map);
	fill(text_map, (t_map){pos.cols - 1, pos.rows}, map);
	fill(text_map, (t_map){pos.cols, pos.rows + 1}, map);
}

int	check_way(char **text_map, t_map map)
{
	t_map	pos_p;
	int		y;
	int		x;

	y = 0;
	pos_p = pos_play(text_map);
	fill(text_map, pos_p, map);
	while (text_map[y] != '\0')
	{
		while (text_map[y][x] != '\0')
		{
			if (text_map[y][x] == 'P' || text_map[y][x] == 'E' ||
				text_map[y][x] == 'C')
			{
				free_matrix(text_map);
				return (0);
			}
			x++;
		}
		x = 0;
		y++;
	}
	free_matrix(text_map);
	return (1);
}
