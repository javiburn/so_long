/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarabia <jsarabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:33:50 by jsarabia          #+#    #+#             */
/*   Updated: 2023/04/05 15:34:17 by jsarabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

int	print_error(int error)
{
	if (error == 1)
		ft_printf("Error!\nIncorrect number of arguments given\n");
	if (error == 2)
		ft_printf("Error!\nFailed to allocate memory to create the map\n");
	if (error == 3)
		ft_printf("Error!\nWalls aren't correctly displayed on the map\n");
	if (error == 4)
		ft_printf("Error!\nThe map is not rectangular\n");
	if (error == 5)
		ft_printf("Error!\nThere is no player in that map!\n");
	if (error == 6)
		ft_printf("Error!\nThere is no way to get out of that map!\n");
	if (error == 7)
		ft_printf("Error!\nWait... What are those characters???\n");
	if (error == 8)
		ft_printf("Error!\nWell... That's not even a .ber file\n");
	if (error == 9)
		ft_printf("Error!\nThere are no objects to collect\n");
	if (error == 10)
		ft_printf("Error!\nYou can't reach all the elements\n");
	return (0);
}
