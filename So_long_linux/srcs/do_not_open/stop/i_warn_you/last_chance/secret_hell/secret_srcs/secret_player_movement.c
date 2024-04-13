/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   secret_player_movement.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 18:04:41 by crea              #+#    #+#             */
/*   Updated: 2024/04/07 00:47:14 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../secret_include/secret_hell.h"

void	handle_secret_player_movement(t_secret_game *secret_game, int keycode)
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
	new_x = secret_game->game->map.player_pos.x + delta_x;
	new_y = secret_game->game->map.player_pos.y + delta_y;
	if (!player_bump_boss(secret_game, new_x, new_y) &&
		secret_is_valid_move(secret_game, new_x, new_y, keycode))
		handle_secret_movement_changes(secret_game, new_x, new_y);
	return ;
}

void	handle_secret_movement_changes(t_secret_game *secret_game, int new_x, int new_y)
{
	secret_update_collect_count(secret_game, new_x, new_y);
	secret_check_if_win(secret_game, new_x, new_y);
	secret_update_player_pos(secret_game, new_x, new_y);
	secret_draw_map(secret_game);
}