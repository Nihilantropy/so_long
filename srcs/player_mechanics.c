/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_mechanics.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 12:46:01 by crea              #+#    #+#             */
/*   Updated: 2024/03/30 23:14:01 by crea             ###   ########.fr       */
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
	game->powerup.time = current_timestamp();
	ft_printf(ON_FIRE);
}

void	destroy_enemy(t_game *game)
{
	int	enemy_index;
	int	count;

	enemy_index = 0;
	count = 0;
	game->map.enemy[game->map.enemy_target].alive = false;
	while (enemy_index < game->map.enemies)
	{
		if (!game->map.enemy[enemy_index].alive)
			count++;
		else
			ft_printf(PLAYER_DESTROY_ENEMY);
		if (count == game->map.enemies - 1)
			ft_printf(LAST_ENEMY);
		enemy_index++;
	}
	remove_enemy_from_matrix(game);
}
