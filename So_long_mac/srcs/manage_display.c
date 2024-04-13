/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_display.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:08:58 by crea              #+#    #+#             */
/*   Updated: 2024/04/07 22:26:45 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	open_display(t_game *game)
{
	window	width;
	window	height;

	width = game->win.width;
	height = game->win.height;
	game->mlx_win = mlx_new_window(game->mlx_ptr, width, height, DISPLAY_NAME);
}

void	get_win_size(t_game *game)
{
	game->win.width = game->map.col * TILE_SIZE;
	game->win.height = game->map.row * TILE_SIZE;
}

void	manage_display(t_game *game)
{
	get_win_size(game);
	open_display(game);
	init_sprites(game);
	draw_map(game);
	return ;
}
