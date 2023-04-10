/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_elements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarabia <jsarabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 14:50:04 by jsarabia          #+#    #+#             */
/*   Updated: 2023/04/05 15:29:56 by jsarabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

t_map	ft_map_coord(char *argv)
{
	t_map	map;
	int		fd;
	char	*ptr;

	fd = open(argv, O_RDONLY);
	ptr = get_next_line(fd);
	map.cols = 0;
	map.rows = 0;
	if (ptr == NULL)
		return (map);
	map.cols = ft_strlen(ptr) - 1;
	while (1)
	{
		if (ptr == NULL)
			break ;
		map.rows++;
		free(ptr);
		ptr = get_next_line(fd);
	}
	close(fd);
	return (map);
}

char	**ft_text_map(char *argv, t_map map)
{
	int		fd;
	char	*ptr;
	char	**text_map;
	int		rows;

	rows = 0;
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		return (0);
	text_map = (char **)ft_calloc(map.rows + 1, sizeof(char *));
	while (rows < map.rows)
	{
		ptr = get_next_line(fd);
		if (ptr == NULL)
			break ;
		if ((int)ft_strlen(ptr) - 1 != map.cols)
			return (NULL);
		text_map[rows] = ft_calloc(map.cols + 2, sizeof(char));
		ft_strlcpy(text_map[rows], ptr, map.cols + 2);
		rows++;
		free(ptr);
		ptr = NULL;
	}
	close(fd);
	return (text_map);
}

int	player_pos(char **map, t_disp *d)
{
	int	count;
	int	x;
	int	y;

	x = 0;
	y = 0;
	count = 0;
	while (map[y] != '\0')
	{
		while (map[y][x] != '\0')
		{
			if (map[y][x] == 'P')
			{
				d->player.y = y;
				d->player.x = x;
				count++;
			}
			x++;
		}
		x = 0;
		y++;
	}
	if (count != 1)
		return (0);
	return (count);
}

int	num_cols(char **map, t_disp *display)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	display->number_collects = 0;
	while (map[y] != '\0')
	{
		while (map[y][x] != '\0')
		{
			if (map[y][x] == 'C')
				display->number_collects++;
			x++;
		}
		x = 0;
		y++;
	}
	return (display->number_collects);
}
