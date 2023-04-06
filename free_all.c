/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarabia <jsarabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:37:45 by jsarabia          #+#    #+#             */
/*   Updated: 2023/04/05 15:42:53 by jsarabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

void	free_matrix(char **matrix)
{
	int	y;

	y = 0;
	while (matrix[y] != '\0')
	{
		free(matrix[y]);
		y++;
	}
	free(matrix);
}

void	free_all(t_disp *display)
{
	if (display->text_map)
		free_matrix(display->text_map);
}
