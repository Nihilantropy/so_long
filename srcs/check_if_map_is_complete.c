/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_map_is_complete.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:08:32 by crea              #+#    #+#             */
/*   Updated: 2024/03/30 23:20:08 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	flood_fill(t_game *game, int x, int y,
				char **visited);
static int	verify_collectibles_and_exit(t_game *game,
				char **visited);
static int	verify_result(t_game *game);

static void	flood_fill(t_game *game, int x, int y,
				char **visited);

void		build_bool_matrix(t_game *game, char ***visited);

void		free_bool_matrix(t_game *game, char **visited);

static void	flood_fill(t_game *game, int x, int y, char **visited)
{
	if (x < 0 || y < 0 || x >= game->map.col || y >= game->map.row
		|| visited[y][x] || game->map.matrix[y][x] == WALL
		|| game->map.matrix[y][x] == ENEMY)
		return ;
	visited[y][x] = 1;
	flood_fill(game, x + 1, y, visited);
	flood_fill(game, x - 1, y, visited);
	flood_fill(game, x, y + 1, visited);
	flood_fill(game, x, y - 1, visited);
}

static int	verify_collectibles_and_exit(t_game *game,
										char **visited)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map.row)
	{
		x = 0;
		while (x < game->map.col)
		{
			if (visited[y][x] && game->map.matrix[y][x] == COLLECT)
				game->map.reachable.collect_reachable++;
			if (visited[y][x] && game->map.matrix[y][x] == EXIT)
				game->map.reachable.exit_reachable = 1;
			x++;
		}
		y++;
	}
	if (verify_result(game))
		return (1);
	return (0);
}

static int	verify_result(t_game *game)
{
	if (game->map.reachable.collect_reachable == game->map.collect
		&& game->map.reachable.exit_reachable == 1)
	{
		ft_printf(MAP_CAN_BE_COMPLETED);
		return (1);
	}
	else
	{
		if (game->map.reachable.collect_reachable != game->map.collect)
			ft_printf(ERROR_CANT_REACH_COLLECT);
		if (!game->map.reachable.exit_reachable)
			ft_printf(ERROR_CANT_REACH_EXIT);
		return (0);
	}
}

int	is_map_complete(t_game *game)
{
	char	**visited;

	visited = NULL;
	build_bool_matrix(game, &visited);
	flood_fill(game, game->map.player_pos.x, game->map.player_pos.y, visited);
	//printf_flood_matrix(game, visited);
	if (verify_collectibles_and_exit(game, visited))
	{
		free_bool_matrix(game, visited);
		return (1);
	}
	else
	{
		ft_printf(ERROR_MAP_CANT_BE_COMPLETED);
		free_bool_matrix(game, visited);
		return (0);
	}
}
