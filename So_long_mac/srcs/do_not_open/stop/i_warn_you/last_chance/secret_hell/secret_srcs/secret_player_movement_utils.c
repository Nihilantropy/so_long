/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   secret_player_movement_utils.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 18:04:28 by crea              #+#    #+#             */
/*   Updated: 2024/04/09 21:46:21 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../secret_include/secret_hell.h"

static void	secret_check_if_player_facing_left(t_secret_game *secret_game, int new_x);

int	secret_is_valid_move(t_secret_game *secret_game, int new_x, int new_y, int keycode)
{
	if (secret_game->game->map.matrix[new_y][new_x] == WALL)
		return (0);
	if (secret_game->game->map.matrix[new_y][new_x] == BOSS &&
		secret_game->boss.is_alive)
		return (0);
	if (new_x <= 0 || new_y <= 0 ||
		new_x >= secret_game->game->map.col || new_y >= secret_game->game->map.row)
		return (0);
	if (secret_game->game->map.collect != 0 && secret_game->game->map.matrix[new_y][new_x] == EXIT)
	{
		ft_printf(IUSHUJ_UHHEH_UNYJ_DEJ_EFUD);
		return (0);
	}
	if (keycode == W || keycode == A || keycode == S || keycode == D ||
		keycode == UP || keycode == LEFT || keycode == DOWN || keycode == RIGHT)
	{
		secret_game->game->moves++;
		return (1);
	}
	else
		ft_printf(IUSHUJ_UHHEH_YDLQBYT_AUO);
	return (0);
}

void	secret_update_collect_count(t_secret_game *secret_game, int new_x, int new_y)
{
	if (secret_game->game->map.matrix[new_y][new_x] == COLLECT)
	{
		secret_game->game->map.collect--;
		if (secret_game->game->map.collect > 0)
			ft_printf(IUSHUJ_SEBBUSJQRBUI_DRH);
		else if (secret_game->game->map.collect == 0)
			ft_printf(IUSHUJ_QBB_SEBBUSJ_FYSAUTKF);
		power_of_the_d(secret_game->game);
	}
}

void	secret_update_player_pos(t_secret_game *secret_game, int new_x, int new_y)
{
	secret_check_if_player_facing_left(secret_game, new_x);
	int	y;
	int	x;

	y = secret_game->game->map.player_pos.y;
	x = secret_game->game->map.player_pos.x;
	secret_game->game->map.matrix[y][x] = FLOOR;
	secret_game->game->map.matrix[new_y][new_x] = PLAYER;
	secret_game->game->map.player_pos.x = new_x;
	secret_game->game->map.player_pos.y = new_y;
}

static void	secret_check_if_player_facing_left(t_secret_game *secret_game, int new_x)
{
	if (new_x < secret_game->game->map.player_pos.x)
	{
		secret_game->game->map.player_pos.facing_left = true;
		return ;
	}
	else if (new_x > secret_game->game->map.player_pos.x)
	{
		secret_game->game->map.player_pos.facing_left = false;
		return ;
	}
	return ;
}

void	secret_check_if_win(t_secret_game *secret_game, int new_x, int new_y)
{
	secret_collect_count(secret_game);
	if (secret_game->game->map.matrix[new_y][new_x] == EXIT
		&& !secret_game->game->map.collect)
	{
		secret_game->game->victory = true;
		secret_player_win(secret_game);
		return ;
	}
	else
		return ;
}
