/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:09:06 by crea              #+#    #+#             */
/*   Updated: 2024/04/09 21:52:01 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	handle_key_event(t_game *game)
{
	mlx_hook(game->mlx_win, DESTROY_WIN_CLIENT_MSG, 0, close_game, game);
	mlx_key_hook(game->mlx_win, key_press, game);
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == ESC)
	{
		ft_printf(EARLY_GAME_CLOSE);
		close_game(game);
	}
	else
		handle_player_movement(game, keycode);
	return (0);
}

void	handle_player_movement(t_game *game, int keycode)
{
	int	delta_x;
	int	delta_y;
	int	new_x;
	int	new_y;

	delta_x = 0;
	delta_y = 0;
	if (keycode == W || keycode == UP)
		delta_y = -1;
	else if (keycode == A || keycode == LEFT)
		delta_x = -1;
	else if (keycode == S || keycode == DOWN)
		delta_y = 1;
	else if (keycode == D || keycode == RIGHT)
		delta_x = 1;
	new_x = game->map.player_pos.x + delta_x;
	new_y = game->map.player_pos.y + delta_y;
	if (is_valid_move(game, new_x, new_y, keycode)
		&& !player_bump_enemy(game, new_x, new_y))
		handle_movement_changes(game, new_x, new_y);
	return ;
}

void	handle_movement_changes(t_game *game, int new_x, int new_y)
{
	update_collect_count(game, new_x, new_y);
	check_if_win(game, new_x, new_y);
	update_player_pos(game, new_x, new_y);
	draw_map(game);
	if (game->victory == true)
		player_win(game);
}

int	try_to_drill(t_game *game, int new_x, int new_y)
{
	if (game->map.matrix[new_y][new_x] == WALL && !game->can_escape)
	{
		ft_printf(ERROR_INVALID_ROUT);
		return (0);
	}
	else if (game->map.matrix[new_y][new_x] == WALL && game->can_escape)
	{
		game->map.holes++;
		if (game->map.holes == BREACH)
		{
			game->escaped = true;
			ft_printf(SECRET_LOCKED);
		}
		return (0);
	}
	return (1);
}
