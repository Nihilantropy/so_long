/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_extention.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:08:40 by crea              #+#    #+#             */
/*   Updated: 2024/03/25 16:26:02 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_map_ext(char *map_file)
{
	int	len;

	len = ft_strlen(map_file) - 1;
	if (map_file[len] == 'r' && map_file[len - 1] == 'e'
		&& map_file[len - 2] == 'b' && map_file[len - 3] == '.')
		return (ft_printf(CORRECT_MAP_EXT));
	else
	{
		ft_printf(ERROR_MAP_EXT);
		return (0);
	}
}
