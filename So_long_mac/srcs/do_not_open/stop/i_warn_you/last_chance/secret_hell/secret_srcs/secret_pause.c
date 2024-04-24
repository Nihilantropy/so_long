/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   secret_pause.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 15:26:58 by crea              #+#    #+#             */
/*   Updated: 2024/04/08 22:21:25 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../secret_include/secret_hell.h"

void	draw_pause_overlay(t_secret_game *secret_game)
{
	int	x;
	int	y;

	y = 0;
	while (y < secret_game->game->map.row)
	{
		x = 0;
		while (x < secret_game->game->map.col)
		{
			secret_game->game->tiles.x = x;
			secret_game->game->tiles.y = y;
			secret_render_tiles(secret_game, secret_game->game->map.matrix[y][x]);
			mlx_put_image_to_window(secret_game->mlx_ptr, secret_game->mlx_win,
									secret_game->tiles.pause.screen,
									x * TILE_SIZE,
									y * TILE_SIZE);
			x++;
		}
		y++;
	}
	draw_health(secret_game);
	draw_text(secret_game->game);
	mlx_put_image_to_window(secret_game->mlx_ptr, secret_game->mlx_win, secret_game->tiles.pause.stop,
			secret_game->game->win.width / 2 - 5, secret_game->game->win.height / 2);
}

int	secret_pause_update(void)
{
	usleep(FRAME_TIME_US);
	return (0);
}

void	secret_pause(t_secret_game *secret_game)
{
	draw_pause_overlay(secret_game);
	mlx_hook(secret_game->mlx_win, DESTROY_WIN_CLIENT_MSG, 0, secret_close_game, secret_game);
	mlx_key_hook(secret_game->mlx_win, secret_cheat_wrapper, secret_game);
	mlx_loop_hook(secret_game->mlx_ptr, secret_pause_update, secret_game);
	mlx_loop(secret_game->mlx_ptr);
}

int	secret_cheat_wrapper(int keycode, void *param)
{
	t_secret_game	*secret_game;
	
	secret_game = (t_secret_game *)param;
	return (secret_cheat(secret_game, keycode));
}

void	create_pause_screen(t_secret_game *secret_game)
{
	int	width;
	int	height;

	width = TILE_SIZE;
	height = TILE_SIZE;
	secret_game->tiles.pause.stop = mlx_xpm_file_to_image(secret_game->mlx_ptr, PAUSE_LOGO_SPRITE, &width, &height);
	secret_game->tiles.pause.screen = mlx_new_image(secret_game->mlx_ptr, TILE_SIZE, TILE_SIZE);
	if (!secret_game->tiles.pause.screen)
		ft_exit_error(ERROR_CREATE_PUASE_IMAGE);
	unsigned int *image_data = (unsigned int *)mlx_get_data_addr(secret_game->tiles.pause.screen,
																&(int){0}, &(int){0}, &(int){0});
	unsigned int gray_color = 0x808080;
	for (int y = 0; y < TILE_SIZE; y++) {
		for (int x = 0; x < TILE_SIZE; x++) {
			image_data[y * TILE_SIZE + x] = (gray_color & 0xFFFFFF) | (TRANSPARENCY_LEVEL << 24);
		}
	}
}