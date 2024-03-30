/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_mechanics.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 12:46:01 by crea              #+#    #+#             */
/*   Updated: 2024/03/30 20:47:24 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/* player moves and bump into an enemy */
int	player_bump_enemy(t_game *game, int new_x, int new_y)
{
	if (game->map.matrix[new_y][new_x] == ENEMY && !game->powerup.the_d)
	{
		player_lose(game, PLAYER_GOT_CAUGHT);
		print_matrix(game);
		return (1);
	}
	else if (game->map.matrix[new_y][new_x] == ENEMY && game->powerup.the_d)
	{
		get_enemy_target(game, new_x, new_y);
		destroy_enemy(game);
		handle_movement_changes(game, new_x, new_y);
		return (1);
	}
	return (0);
}

/* player power up after collecting an item */
void	power_of_the_d(t_game *game)
{
	game->powerup.the_d = true;
}

void	destroy_enemy(t_game *game)
{
	game->map.enemy[game->map.enemy_target].alive = false;
	remove_enemy_from_matrix(game);
	//game->powerup.the_d = false;
}
