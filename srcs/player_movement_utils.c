/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:09:01 by crea              #+#    #+#             */
/*   Updated: 2024/03/30 23:22:35 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	is_valid_move(t_game *game, int new_x, int new_y, int keycode)
{
	if (game->map.matrix[new_y][new_x] == WALL)
	{
		ft_printf(ERROR_INVALID_ROUT);
		return (0);
	}
	if (new_x <= 0 || new_y <= 0 ||
		new_x >= game->map.col || new_y >= game->map.row)
		return (0);
	if (game->map.collect != 0 && game->map.matrix[new_y][new_x] == EXIT)
	{
		ft_printf(ERROR_EXIT_NOT_OPEN);
		return (0);
	}
	if (keycode == W || keycode == A || keycode == S || keycode == D ||
		keycode == UP || keycode == LEFT || keycode == DOWN || keycode == RIGHT)
	{
		game->moves++;
		return (1);
	}
	else
		ft_printf(ERROR_INVALID_KEY);
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
	{
		ft_printf(FINAL_PLAYER_POS);
		return ;
	}
	else
	{
		//ft_printf(NEW_PLAYER_POS);
		ft_printf(MOVES_NBR);
		return ;
	}
}

void	update_collect_count(t_game *game, int new_x, int new_y)
{
	if (game->map.matrix[new_y][new_x] == COLLECT)
	{
		if (game->map.collect > 1)
			ft_printf(COLLECTABLES_NBR);
		else if (game->map.collect == 1)
			ft_printf(ALL_COLLECT_PICKEDUP);
		game->map.collect--;
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
