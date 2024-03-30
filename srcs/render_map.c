/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 12:56:30 by crea              #+#    #+#             */
/*   Updated: 2024/03/30 22:30:22 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	draw_text(t_game *game);

void    init_sprites(t_game *game)
{
    void    *mlx_ptr;
    int width;
    int height;

    width = game->tiles.width;
    height = game->tiles.height;
    mlx_ptr = game->mlx_ptr;
    game->tiles.floor = mlx_xpm_file_to_image(mlx_ptr, FLOOR_SPRITE, &width, &height);
    load_wall_images(game);
    load_player_images(game);
	load_player_d_images(game);
    load_player_inv_images(game);
	load_player_d_inv_images(game);
    load_collect_images(game);
    load_exit_images(game);
	load_enemy_images(game);
}

void    render_tiles(t_game *game, char tile)
{
    void *image;

    image = handle_diff_player_anim(game, tile);
    if (tile == FLOOR)
        image = game->tiles.floor;
    else if (tile == WALL)
        image = game->tiles.wall.frames[game->tiles.wall.current_frame];
    else if (tile == COLLECT)
        image = game->tiles.collect.frames[game->tiles.collect.current_frame];
    else if (tile == EXIT)
        image = game->tiles.exit.frames[game->tiles.exit.current_frame];
	else if (tile == ENEMY)
		image = game->tiles.enemy.frames[game->tiles.enemy.current_frame];
    if (image)
        mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
            image, game->tiles.x * TILE_SIZE, game->tiles.y * TILE_SIZE);
}

void    draw_map(t_game *game)
{
    int y;
    int x;

    mlx_clear_window(game->mlx_ptr, game->mlx_win);
    y = 0;
    while (y < game->map.row)
    {
        x = 0;
        while (game->map.matrix[y][x])
        {
            game->tiles.x = x;
            game->tiles.y = y;
            render_tiles(game, game->map.matrix[y][x]);  
            x++;
        }
        y++;
    }
	draw_text(game);
}

void free_images(t_game *game)
{
    if (!game->mlx_ptr || !game->tiles.floor || !game->tiles.wall.frames[0] ||
		!game->tiles.player.frames[0] || !game->tiles.player_inv.frames[0] ||
		!game->tiles.collect.frames[0] || !game->tiles.exit.frames[0] ||
		!game->tiles.enemy.frames[0])
        ft_exit_error(ERROR_FREE_IMAGE);
    mlx_destroy_image(game->mlx_ptr, game->tiles.floor);
    free_wall_images(game);
    free_player_images(game);
	free_player_d_images(game);
    free_player_inv_images(game);
    free_player_d_inv_images(game);
    free_collect_images(game);
    free_exit_images(game);
	free_enemy_images(game);
}

static void	draw_text(t_game *game)
{
	char	*str;

	str = ft_itoa(game->moves);
	if (game->map.collect >= 0)
		mlx_string_put(game->mlx_ptr, game->mlx_win,
			game->win.width - TILE_SIZE / 2.3,
			TILE_SIZE - TILE_SIZE / 1.5,
			-1, str);
	else
		mlx_string_put(game->mlx_ptr, game->mlx_win,
			game->win.width - TILE_SIZE / 2.3,
			TILE_SIZE - TILE_SIZE / 1.5,
			15921152, str);
	free(str);
}
