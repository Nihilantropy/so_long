/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hell_boss_movement_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 17:52:32 by crea              #+#    #+#             */
/*   Updated: 2024/04/09 21:49:15 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../secret_include/secret_hell.h"

int	is_boss_valid_move(t_secret_game *secret_game, int new_x, int new_y)
{
	if (secret_game->game->map.matrix[new_y][new_x] == WALL || 
		secret_game->game->map.matrix[new_y][new_x] == EXIT ||
		new_x <= 0 || new_y <= 0 ||
		new_x >= secret_game->game->map.col ||
		new_y >= secret_game->game->map.row)
		return (0);
	return (1);
}

void	secret_update_boss_collect_count(t_secret_game *secret_game, int new_x, int new_y)
{
	if (secret_game->game->map.matrix[new_y][new_x] == COLLECT)
	{
		secret_game->game->map.collect--;
		if (secret_game->game->map.collect > 0)
			ft_printf(SECRET_BOSS_COLLECTABLES_NBR);
		else if (secret_game->game->map.collect == 0)
		{
			secret_game->game->map.collect = -1;	
			ft_printf(CANT_ESCAPE);
		}
	}
}

int player_bump_boss(t_secret_game *secret_game, int new_x, int new_y)
{
	char	current_tile;
	
	current_tile = secret_game->game->map.matrix[new_y][new_x];
	if (current_tile == BOSS || current_tile == WEAPON)
	{
		if (!secret_game->game->powerup.the_d)
			player_lose(secret_game->game, PLAYER_BUMP_BOSS);
		else if (secret_game->game->powerup.the_d && current_tile == BOSS)
		{
			update_boss_health(secret_game);
			if (secret_game->boss.is_alive)
				return (1);
			else
			{
				if (secret_game->cheat_done)
					ft_printf(BOSS_CHEAT);
				else
					ft_printf(BOSS_DEFEATED);
				return (0);
			}
		}	
	}
	return (0);
}

int	boss_hit_player(t_secret_game *secret_game, int new_x, int new_y)
{
	char	current_tile;
	
	current_tile = secret_game->game->map.matrix[new_y][new_x];
	if (current_tile == PLAYER)
	{
		if (!secret_game->game->powerup.the_d && secret_game->player.is_alive)
			player_lose(secret_game->game, BOSS_DESTROY_PLAYER);
		else if (secret_game->game->powerup.the_d && secret_game->player.health > 1)
		{
			update_player_health(secret_game);
			return (1);
		}
		else if (secret_game->game->powerup.the_d && secret_game->player.health <= 1)
		{
			secret_game->player.is_alive = false;
			player_lose(secret_game->game, BOSS_DESTROY_PLAYER);
			return (0);
		}	
	}
	return (0);
}

