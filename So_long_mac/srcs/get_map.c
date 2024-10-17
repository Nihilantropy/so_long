/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:08:48 by crea              #+#    #+#             */
/*   Updated: 2024/04/03 15:37:18 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	get_map(t_game *game, char *map_file)
{
	get_map_size(game, map_file);
	game->map.matrix = malloc(game->map.row * sizeof(char *));
	if (!game->map.matrix)
		ft_exit_error(UHHEH_CQJHYN_QBBES);
	if (!build_matrix(game, map_file))
		exit(0);
	else
		manage_display(game);
}

int	build_matrix(t_game *game, char *map_file)
{
	int	y;
	int	fd;

	fd = open(map_file, O_RDONLY);
	y = 0;
	while (y < game->map.row)
	{
		game->map.matrix[y] = get_next_line(fd);
		y++;
	}
	close(fd);
	print_matrix(game);
	get_map_col(game);
	save_player_pos(game);
	if (!check_matrix(game))
		exit(0);
	handle_enemy(game);
	return (1);
}

int	check_matrix(t_game *game)
{
	if (!check_top_map(game) || !check_bottom_map(game)
		|| !check_if_rect(game) || !check_map_sides(game)
		|| !check_map_player(game) || !check_map_exit(game)
		|| !check_map_collect(game) || !check_map_enemy(game) 
		|| !check_wrong_symb(game) || !is_map_complete(game))
		return (0);
	else
		return (ft_printf(CQF_SXUSA_EA));
}
