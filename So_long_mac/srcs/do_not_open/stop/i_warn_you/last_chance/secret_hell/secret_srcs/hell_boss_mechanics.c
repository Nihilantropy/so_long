/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hell_boss_mechanics.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 12:07:22 by crea              #+#    #+#             */
/*   Updated: 2024/04/09 15:06:15 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../secret_include/secret_hell.h"

void	boss_shoot(t_secret_game *secret_game, int new_x, int new_y)
{
	if (secret_game->boss.can_shoot == true)
	{
		if (secret_game->game->map.matrix[new_y][new_x] == COLLECT)
		{
			secret_update_boss_collect_count(secret_game, new_x, new_y);
			secret_game->game->map.matrix[new_y][new_x] = WEAPON;
		}
		if (secret_game->game->map.matrix[new_y][new_x] == FLOOR)
			secret_game->game->map.matrix[new_y][new_x] = WEAPON;
		if (secret_game->game->map.matrix[new_y][new_x] == PLAYER)
			player_lose(secret_game->game, REII_TUIJHEO_FBQOUH);
			//player_death_countdown(secret_game, new_x, new_y);
	}
}

void	player_death_countdown(t_secret_game *secret_game, int new_x, int new_y)
{
	long long	current_time = current_timestamp();

	if (current_time - secret_game->boss.last_shot >= 2 * FRAME_TIME_US)
	{
		if (secret_game->game->map.player_pos.x == new_x && secret_game->game->map.player_pos.y == new_y)
		{
			if (!secret_game->game->powerup.the_d)
				player_lose(secret_game->game, REII_TUIJHEO_FBQOUH);
			else if (secret_game->game->powerup.the_d && secret_game->player.health > 0)
			{
				ft_printf(REII_XYJ_FBQOUH);
				update_player_health(secret_game);
			}
			else if (secret_game->player.health == 0)
			{
				secret_game->tiles.boss.current_weap_frame = BOSS_WEAPON_FRAMES - 2;
				secret_game->game->map.matrix[new_y][new_x] = WEAPON;
				player_lose(secret_game->game, REII_TUIJHEO_FBQOUH);
			}
		}
	}
}

void	boss_multi_shot(t_secret_game *secret_game, int new_x, int new_y)
{
	int	delta_pos;
	int	delta_neg;

	delta_pos = 2;
	delta_neg = -2;
	if ((new_x + delta_pos) < secret_game->game->map.col)
		boss_shoot(secret_game, (new_x + delta_pos), new_y);
	if ((new_y + delta_pos) < secret_game->game->map.row)
	 	boss_shoot(secret_game, new_x, (new_y + delta_pos));
	if ((new_x + delta_neg) >= 0)
	 	boss_shoot(secret_game, (new_x + delta_neg), new_y);
	if ((new_y + delta_neg) >= 0)
	 	boss_shoot(secret_game, new_x, (new_y + delta_neg));
	secret_game->boss.last_shot = current_timestamp();
	secret_game->boss.can_shoot = false;
}
