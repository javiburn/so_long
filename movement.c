/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarabia <jsarabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 14:46:29 by jsarabia          #+#    #+#             */
/*   Updated: 2023/04/06 14:47:04 by jsarabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

int	move_up(t_disp *d, int *num)
{
	if (d->text_map[d->player.y - 1][d->player.x] != '1')
	{
		*num += 1;
		ft_printf("You have made %d movements\n", *num);
		if (d->text_map[d->player.y - 1][d->player.x] == 'E'
			&& d->number_collects < 1)
			exit(0);
		else
		{
			if (d->text_map[d->player.y - 1][d->player.x] == 'C')
				d->number_collects--;
			d->text_map[d->player.y][d->player.x] = d->char_readed;
			if (d->text_map[d->player.y - 1][d->player.x] != 'E')
				d->char_readed = '0';
			else if (d->text_map[d->player.y - 1][d->player.x] == 'E')
				d->char_readed = 'E';
			d->player.y--;
			d->text_map[d->player.y][d->player.x] = 'P';
			display_floor(d, d->player.y, d->player.x);
			display_player(d);
			display_floor(d, d->player.y + 1, d->player.x);
		}
	}
	return (0);
}

int	move_left(t_disp *d, int *num)
{
	if (d->text_map[d->player.y][d->player.x - 1] != '1')
	{
		*num += 1;
		ft_printf("You have made %d movements\n", *num);
		if (d->text_map[d->player.y][d->player.x - 1] == 'E'
			&& d->number_collects < 1)
			exit(0);
		else
		{
			if (d->text_map[d->player.y][d->player.x - 1] == 'C')
				d->number_collects--;
			d->text_map[d->player.y][d->player.x] = d->char_readed;
			if (d->text_map[d->player.y][d->player.x - 1] != 'E')
				d->char_readed = '0';
			else if (d->text_map[d->player.y][d->player.x - 1] == 'E')
				d->char_readed = 'E';
			d->player.x--;
			d->text_map[d->player.y][d->player.x] = 'P';
			display_floor(d, d->player.y, d->player.x);
			display_player(d);
			display_floor(d, d->player.y, d->player.x + 1);
		}
	}
	return (0);
}

int	move_right(t_disp *d, int *num)
{
	if (d->text_map[d->player.y][d->player.x + 1] != '1')
	{
		*num += 1;
		ft_printf("You have made %d movements\n", *num);
		if (d->text_map[d->player.y][d->player.x + 1] == 'E'
			&& d->number_collects < 1)
			exit(0);
		else
		{
			if (d->text_map[d->player.y][d->player.x + 1] == 'C')
				d->number_collects--;
			d->text_map[d->player.y][d->player.x] = d->char_readed;
			if (d->text_map[d->player.y][d->player.x + 1] != 'E')
				d->char_readed = '0';
			else if (d->text_map[d->player.y][d->player.x + 1] == 'E')
				d->char_readed = 'E';
			d->player.x++;
			d->text_map[d->player.y][d->player.x] = 'P';
			display_floor(d, d->player.y, d->player.x);
			display_player(d);
			display_floor(d, d->player.y, d->player.x - 1);
		}
	}
	return (0);
}

int	move_down(t_disp *d, int *num)
{
	if (d->text_map[d->player.y + 1][d->player.x] != '1')
	{
		*num += 1;
		ft_printf("You have made %d movements\n", *num);
		if (d->text_map[d->player.y + 1][d->player.x] == 'E'
			&& d->number_collects < 1)
			exit(0);
		else
		{
			if (d->text_map[d->player.y + 1][d->player.x] == 'C')
				d->number_collects--;
			d->text_map[d->player.y][d->player.x] = d->char_readed;
			if (d->text_map[d->player.y + 1][d->player.x] != 'E')
				d->char_readed = '0';
			else if (d->text_map[d->player.y + 1][d->player.x] == 'E')
				d->char_readed = 'E';
			d->player.y++;
			d->text_map[d->player.y][d->player.x] = 'P';
			display_floor(d, d->player.y, d->player.x);
			display_player(d);
			display_floor(d, d->player.y - 1, d->player.x);
		}
	}
	return (0);
}
