/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_mechanics_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 15:17:09 by crea              #+#    #+#             */
/*   Updated: 2024/03/30 20:33:49 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	get_enemy_target(t_game *game, int new_x, int new_y)
{
	int	enemy_index;

	enemy_index = 0;
	while (enemy_index < game->map.enemies)
	{
		if (new_y == game->map.enemy[enemy_index].enemy_pos.y &&
			new_x == game->map.enemy[enemy_index].enemy_pos.x)
		{
			game->map.enemy_target = game->map.enemy[enemy_index].index;
			return ;
		}
		enemy_index++;
	}
}

void	remove_enemy_from_matrix(t_game *game)
{
	int	enemy_pos_y;
	int	enemy_pos_x;

	enemy_pos_y = game->map.enemy[game->map.enemy_target].enemy_pos.y;
	enemy_pos_x = game->map.enemy[game->map.enemy_target].enemy_pos.x;
	game->map.matrix[enemy_pos_y][enemy_pos_x] = FLOOR;
}