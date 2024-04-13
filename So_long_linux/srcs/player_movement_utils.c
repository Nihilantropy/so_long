/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:09:01 by crea              #+#    #+#             */
/*   Updated: 2024/04/09 21:35:49 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	is_valid_move(t_game *game, int new_x, int new_y, int keycode)
{
	if (!try_to_drill(game, new_x, new_y))
		return (0);
	if (new_x <= 0 || new_y <= 0 ||
		new_x >= game->map.col || new_y >= game->map.row)
		return (0);
	if (game->map.collect != 0 && game->map.matrix[new_y][new_x] == EXIT)
	{
		ft_printf(UHHEH_UNYJ_DEJ_EFUD);
		return (0);
	}
	if (keycode == W || keycode == A || keycode == S || keycode == D ||
		keycode == UP || keycode == LEFT || keycode == DOWN || keycode == RIGHT)
	{
		game->moves++;
		return (1);
	}
	else
		ft_printf(UHHEH_YDLQBYT_AUO);
	return (0);
}

void	update_player_pos(t_game *game, int new_x, int new_y)
{
	check_if_player_facing_left(game, new_x);
	game->map.matrix[game->map.player_pos.y][game->map.player_pos.x] = FLOOR;
	game->map.matrix[new_y][new_x] = PLAYER;
	game->map.player_pos.x = new_x;
	game->map.player_pos.y = new_y;
	if (game->victory == true)
		return ;
}

void	update_collect_count(t_game *game, int new_x, int new_y)
{
	if (game->map.matrix[new_y][new_x] == COLLECT)
	{
		game->map.collect--;
		if (game->map.collect > 1)
			ft_printf(SEBBUSJQRBUI_DRH);
		else if (game->map.collect == 1)
			ft_printf(QBB_SEBBUSJ_FYSAUTKF);
		power_of_the_d(game);
	}
}

void	check_if_player_facing_left(t_game *game, int new_x)
{
	if (new_x < game->map.player_pos.x)
	{
		game->map.player_pos.facing_left = true;
		return ;
	}
	else if (new_x > game->map.player_pos.x)
	{
		game->map.player_pos.facing_left = false;
		return ;
	}
	return ;
}

void	check_if_win(t_game *game, int new_x, int new_y)
{
	if (game->map.matrix[new_y][new_x] == EXIT && game->map.collect == 0)
	{
		game->victory = true;
		return ;
	}
	else
		return ;
}
