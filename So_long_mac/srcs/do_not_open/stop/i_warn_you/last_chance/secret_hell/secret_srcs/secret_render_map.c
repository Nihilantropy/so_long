/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   secret_render_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 18:50:48 by crea              #+#    #+#             */
/*   Updated: 2024/04/09 21:47:43 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../secret_include/secret_hell.h"

void	secret_init_sprites(t_secret_game *secret_game)
{
	load_boss_images(secret_game);
	load_boss_health_images(secret_game);
	load_player_health_images(secret_game);
	load_boss_weapon_images(secret_game);
	create_pause_screen(secret_game);
}

void	secret_render_tiles(t_secret_game *secret_game, char tile)
{
	void	*image;

	image = handle_diff_player_anim(secret_game->game, tile);
	if (tile == FLOOR)
		image = secret_game->game->tiles.floor;
	else if (tile == WALL)
		image = secret_game->game->tiles.wall.frames[secret_game->game->tiles.wall.current_frame];
	else if (tile == COLLECT)
		image = secret_game->game->tiles.collect.frames[secret_game->game->tiles.collect.current_frame];
	else if (tile == EXIT)
		image = secret_game->game->tiles.exit.frames[secret_game->game->tiles.exit.current_frame];
	else if (tile == ENEMY)
		image = secret_game->game->tiles.enemy.frames[secret_game->game->tiles.enemy.current_frame];
	else if (tile == BOSS)
		image = secret_game->tiles.boss.frames[secret_game->tiles.boss.current_frame];
	else if (tile == WEAPON)
		image = secret_game->tiles.boss.weapon_frames[secret_game->tiles.boss.current_weap_frame];
	if (image)
		mlx_put_image_to_window(secret_game->mlx_ptr, secret_game->mlx_win,
			image, secret_game->game->tiles.x * TILE_SIZE, secret_game->game->tiles.y * TILE_SIZE);
}

void	secret_draw_map(t_secret_game *secret_game)
{
	int	y;
	int	x;

	mlx_clear_window(secret_game->mlx_ptr, secret_game->mlx_win);
	y = 0;
	while (y < secret_game->game->map.row)
	{
		x = 0;
		while (secret_game->game->map.matrix[y][x])
		{
			secret_game->game->tiles.x = x;
			secret_game->game->tiles.y = y;
			secret_render_tiles(secret_game, secret_game->game->map.matrix[y][x]);
			x++;
		}
		y++;
	}
	draw_health(secret_game);
	draw_text(secret_game->game);
}

void secret_free_images(t_secret_game *secret_game)
{
	if (!secret_game->mlx_ptr || !secret_game->game->tiles.floor || 
		!secret_game->game->tiles.wall.frames[0] || !secret_game->game->tiles.player.frames[0] ||
		!secret_game->game->tiles.player_inv.frames[0] || !secret_game->game->tiles.player_d_inv.frames[0] ||
		!secret_game->game->tiles.player_d.frames[0] || !secret_game->game->tiles.collect.frames[0] ||
		!secret_game->game->tiles.exit.frames[0] || !secret_game->game->tiles.enemy.frames[0] ||
		!secret_game->game->tiles.number.count[0] || !secret_game->tiles.boss.frames[0] ||
		!secret_game->tiles.boss.health[0] || !secret_game->player.health_bar[0] ||
		!secret_game->player.health_bar[0])
		ft_exit_error(SECRET_ERROR_FREE_IMAGE);
	mlx_destroy_image(secret_game->game->mlx_ptr, secret_game->game->tiles.floor);
	free_wall_images(secret_game->game);
	free_player_images(secret_game->game);
	free_player_d_images(secret_game->game);
	free_player_inv_images(secret_game->game);
	free_player_d_inv_images(secret_game->game);
	free_collect_images(secret_game->game);
	free_exit_images(secret_game->game);
	free_enemy_images(secret_game->game);
	free_number_images(secret_game->game);
	free_boss_images(secret_game);
	free_boss_health_images(secret_game);
	free_player_health_images(secret_game);
	free_boss_weapon_images(secret_game);
	mlx_destroy_image(secret_game->mlx_ptr, secret_game->tiles.pause.stop);
	mlx_destroy_image(secret_game->mlx_ptr, secret_game->tiles.pause.screen);
}

void	draw_health(t_secret_game *secret_game)
{
	void	*image_1;
	void	*image_2;
	int		x;
	int		y;

	x = (secret_game->game->win.width / 2) + (TILE_SIZE * 3);
	y = TILE_SIZE;
	image_1 = secret_game->tiles.boss.health[secret_game->tiles.boss.current_health];
	mlx_put_image_to_window(secret_game->mlx_ptr, secret_game->mlx_win, image_1, x, y);
	x = (secret_game->game->win.width / 2) - (TILE_SIZE * 3);
	image_2 = secret_game->player.health_bar[secret_game->player.current_health];
	mlx_put_image_to_window(secret_game->mlx_ptr, secret_game->mlx_win, image_2, x, y);
}