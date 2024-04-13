/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_mechanics.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 12:46:01 by crea              #+#    #+#             */
/*   Updated: 2024/04/09 21:39:27 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/* player moves and bump into an enemy */
int	player_bump_enemy(t_game *game, int new_x, int new_y)
{
	if (game->map.matrix[new_y][new_x] == ENEMY && !game->powerup.the_d)
	{
		player_lose(game, FBQOUH_WEJ_SQKWXJ);
		return (1);
	}
	else if (game->map.matrix[new_y][new_x] == ENEMY && game->powerup.the_d)
	{
		get_enemy_target(game, new_x, new_y);
		destroy_enemy(game);
		handle_movement_changes(game, new_x, new_y);
		return (1);
	}
	else
		return (0);
}

/* player power up after collecting an item */
void	power_of_the_d(t_game *game)
{
	game->powerup.the_d = true;
	game->powerup.time = current_timestamp();
	if (!game->map.enemies_alive && game->powerup.the_d)
		game->can_escape = true;
	ft_printf(ED_VYHU);
}

void	depression_of_the_d(t_game *game)
{
	game->powerup.the_d = false;
	game->can_escape = false;
	game->powerup.time = 0;
	game->map.holes = 0;
}

void	destroy_enemy(t_game *game)
{
	game->map.enemy[game->map.enemy_target].alive = false;
	game->map.enemies_alive--;
	if (game->map.enemies_alive > 1)
	{
		ft_printf(FBQOUH_TUIJHEO_UDUCO);
		ft_printf(UDUCYUI_QBYLU_DRH);
	}
	else if (game->map.enemies_alive == 1)
	{
		ft_printf(FBQOUH_TUIJHEO_UDUCO);
		ft_printf(UDUCO_QBYLU_1);
	}
	else if (game->map.enemies_alive == 0)
		ft_printf(DE_CEHU_UDUCYUI);
	remove_enemy_from_matrix(game);
}

