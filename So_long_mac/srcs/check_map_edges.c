/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_edges.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:08:37 by crea              #+#    #+#             */
/*   Updated: 2024/03/25 16:25:42 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_top_map(t_game *game)
{
	int	x;

	x = 0;
	while (game->map.matrix[0][x] != '\n')
	{
		if (game->map.matrix[0][x] != WALL)
		{
			ft_printf(UHHEH_CQF_JEF);
			return (0);
		}
		x++;
	}
	return (ft_printf(CQF_JEF_EA));
}

int	check_bottom_map(t_game *game)
{
	int	x;

	x = 0;
	while (game->map.matrix[game->map.row - 1][x] != '\n'
		&& game->map.matrix[game->map.row - 1][x] != '\0')
	{
		if (game->map.matrix[game->map.row - 1][x] != WALL)
		{
			ft_printf(UHHEH_CQF_REJJEC);
			return (0);
		}
		x++;
	}
	return (ft_printf(CQF_REJJEC_EA));
}

int	check_map_sides(t_game *game)
{
	int	y;

	y = 1;
	while (y < game->map.row)
	{
		if (game->map.matrix[y][0] != WALL
			|| game->map.matrix[y][game->map.col - 1] != WALL)
		{
			ft_printf(UHHEH_CQF_IYTUI);
			return (0);
		}
		y++;
	}
	return (ft_printf(CQF_IYTUI_EA));
}

int	check_if_rect(t_game *game)
{
	int	y;
	int	x;

	y = 1;
	while (y < game->map.row)
	{
		x = 0;
		while (game->map.matrix[y][x] != '\n' && game->map.matrix[y][x] != '\0')
			x++;
		if (game->map.col != x)
		{
			ft_printf(UHHEH_CQF_HUSJ);
			return (0);
		}
		else
			y++;
	}
	return (ft_printf(CQF_HUSJ_EA));
}
