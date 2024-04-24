/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_mechanics.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 15:47:51 by crea              #+#    #+#             */
/*   Updated: 2024/04/09 21:39:12 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/* enemy moves and catch the player */
int	enemy_bump_player(t_game *game, int new_x, int new_y)
{
	if (game->map.matrix[new_y][new_x] == PLAYER && !game->powerup.the_d)
	{
		player_lose(game, PLAYER_GOT_CAUGHT);
		return (1);
	}
	else if (game->map.matrix[new_y][new_x] == PLAYER && game->powerup.the_d)
	{
		self_destroy(game);
		return (1);
	}
	else
	 	return (0);
}

/* enemy movement probability logic */
void	enemy_patrol(t_game *game)
{
	int	probability;

	probability = rand() % ENEMY_MOVE_PROB + 1;
	if (probability == 1)
	{
		while (game->map.enemy_index < game->map.enemies)
		{
			if (game->map.enemy[game->map.enemy_index].alive)
				move_enemy(game);
			game->map.enemy_index++;
	
		}
		game->map.enemy_index = 0;
	}
	return ;
}

void move_enemy(t_game *game)
{
	int	new_x;
	int	new_y;
	int	delta_x;
	int	delta_y;
	int direction;

	delta_x = 0;
	delta_y = 0;
    direction = random_range(0, 3);
    if (direction == 0)
		delta_y = -1;
    else if (direction == 1)
        delta_y = 1;
    else if (direction == 2)
		delta_x = -1;
    else if (direction == 3)
		delta_x = 1;
	else
		return ;
	new_x = game->map.enemy[game->map.enemy_index].enemy_pos.x + delta_x;
	new_y = game->map.enemy[game->map.enemy_index].enemy_pos.y + delta_y;
	if (is_valid_enemy_move(game, new_x, new_y)
		&& !enemy_bump_player(game, new_x, new_y))
		update_enemy_pos(game, new_x, new_y);
}

void	update_enemy_pos(t_game *game, int new_x, int new_y)
{
	game->map.matrix[game->map.enemy[game->map.enemy_index].enemy_pos.y][game->map.enemy[game->map.enemy_index].enemy_pos.x] = FLOOR;
	game->map.matrix[new_y][new_x] = ENEMY;
	game->map.enemy[game->map.enemy_index].enemy_pos.x = new_x;
	game->map.enemy[game->map.enemy_index].enemy_pos.y = new_y;
}

void	self_destroy(t_game *game)
{
	int	enemy_pos_y;
	int	enemy_pos_x;

	enemy_pos_y = game->map.enemy[game->map.enemy_index].enemy_pos.y;
	enemy_pos_x = game->map.enemy[game->map.enemy_index].enemy_pos.x;
	game->map.enemy[game->map.enemy_index].alive = false;
	if (!game->map.enemy[game->map.enemy_index].alive)
	{
		game->map.enemies_alive--;
		if (game->map.enemies_alive > 1)
		{
			ft_printf(ENEMY_BUMP_PLAYER);
			ft_printf(ENEMIES_ALIVE_NBR);
		}
		else if (game->map.enemies_alive == 1)
		{
			ft_printf(ENEMY_BUMP_PLAYER);
			ft_printf(ENEMY_ALIVE_1);
		}
		else if (game->map.enemies_alive == 0)
			ft_printf(NO_MORE_ENEMIES);
	}
	game->map.matrix[enemy_pos_y][enemy_pos_x] = FLOOR;
	return ;
}