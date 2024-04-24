/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_mechanics_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 16:25:43 by crea              #+#    #+#             */
/*   Updated: 2024/03/31 14:46:49 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void    build_enemy_arr(t_game *game)
{
    int     enemy_nbr;
    int     enemy_index;

    enemy_nbr = game->map.enemies;
    enemy_index = 0;
    if (enemy_nbr > 0)
    {
        game->map.enemy = (t_enemy *)malloc(sizeof(t_enemy) * enemy_nbr);
        if (!game->map.enemy)
            ft_exit_error(ERROR_ENEMY_ALLOC);
        while (enemy_index < enemy_nbr)
        {
            game->map.enemy[enemy_index].alive = true;
            game->map.enemy[enemy_index].index = enemy_index;
            enemy_index++;
        }
    }
}

void	save_enemy_pos(t_game *game)
{
	int	y;
	int	x;
	int	enemy_index;

	y = 1;
	enemy_index = 0;
	while (y < game->map.row - 1)
	{
		x = 1;
		while (game->map.matrix[y][x])
		{
			if (game->map.matrix[y][x] == ENEMY &&
				enemy_index < game->map.enemies)
			{
				game->map.enemy[enemy_index].enemy_pos.x = x;
				game->map.enemy[enemy_index].enemy_pos.y = y;
				enemy_index++;
			}
			x++;
		}
		y++;
	}
}

int	is_valid_enemy_move(t_game *game, int new_x, int new_y)
{
	if (game->map.matrix[new_y][new_x] == WALL ||
		game->map.matrix[new_y][new_x] == COLLECT ||
		game->map.matrix[new_y][new_x] == ENEMY ||
		game->map.matrix[new_y][new_x] == EXIT ||
		new_x <= 0 || new_y <= 0 ||
		new_x >= game->map.col ||
		new_y >= game->map.row)
		return (0);
	return (1);
}

void    free_enemy_arr(t_game *game)
{
	free(game->map.enemy);
	game->map.enemy = NULL;
}

void	handle_enemy(t_game *game)
{
	build_enemy_arr(game);
	save_enemy_pos(game);
}
