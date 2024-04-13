/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hell_boss_mechanics_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 12:08:24 by crea              #+#    #+#             */
/*   Updated: 2024/04/09 15:05:44 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../secret_include/secret_hell.h"

void	update_boss_health(t_secret_game *secret_game)
{
	if (secret_game->boss.is_alive)
	{
		secret_game->boss.last_hit = current_timestamp();
		secret_game->boss.is_hit = true;
		if (secret_game->tiles.boss.current_health < BOSS_HEALTH_FRAMES - 1)
		  	secret_game->tiles.boss.current_health++;
		if (secret_game->boss.health > 0)
			secret_game->boss.health--;
		if (secret_game->boss.health == 1)
		{
			secret_game->tiles.boss.current_frame = BOSS_ANIM_FRAMES - 1;
			secret_game->tiles.boss.current_health = BOSS_HEALTH_FRAMES - 1;
		}
		if (secret_game->boss.health == 0)
			secret_game->boss.is_alive = false;
		secret_draw_map(secret_game);
		return ;
	}
}

void	update_player_health(t_secret_game *secret_game)
{
	if (secret_game->player.is_alive)
	{
		secret_game->player.last_hit = current_timestamp();
		secret_game->player.is_hit = true;
		if (secret_game->player.current_health < PLAYER_HEALTH_FRAMES)
			secret_game->player.current_health++;
		if (secret_game->player.health > 0)
			secret_game->player.health--;
		return ;
	}
}

void	destroy_weapon(t_secret_game *secret_game)
{
	int	x;
	int	y;

	y = 0;
	while (y < secret_game->game->map.row)
	{
		x = 0;
		while (x < secret_game->game->map.col)
		{
			if (secret_game->game->map.matrix[y][x] == WEAPON)
				secret_game->game->map.matrix[y][x] = FLOOR;
			x++;
		}
		y++;
	}
}
