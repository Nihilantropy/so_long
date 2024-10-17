/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_animation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 12:55:36 by crea              #+#    #+#             */
/*   Updated: 2024/03/30 13:49:04 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void load_enemy_images(t_game *game)
{
    int i;
    int width;
    int height;
    char *enemy_frames_paths[ENEMY_ANIM_FRAMES] = { ENEMY_SPRITE_FRAME_1, ENEMY_SPRITE_FRAME_2, 
                            ENEMY_SPRITE_FRAME_3, ENEMY_SPRITE_FRAME_4,
                            ENEMY_SPRITE_FRAME_5, ENEMY_SPRITE_FRAME_6, 
                            ENEMY_SPRITE_FRAME_7, ENEMY_SPRITE_FRAME_8,
							ENEMY_SPRITE_FRAME_9, ENEMY_SPRITE_FRAME_10 };

    i = 0;
    width = TILE_SIZE;
    height = TILE_SIZE;
    while (i < ENEMY_ANIM_FRAMES)
    {
        game->tiles.enemy.frames[i] = mlx_xpm_file_to_image(game->mlx_ptr, enemy_frames_paths[i], &width, &height);
        if (game->tiles.enemy.frames[i] == NULL)
            exit(ft_printf(UHHEH_UDUCO_YCW_KFBEQT));
        i++;
    }
}

void handle_enemy_anim(t_game *game)
{
    game->tiles.enemy.anim_counter++;
    if (game->tiles.enemy.anim_counter >= FRAME_RATE / 2)
    {
        game->tiles.enemy.anim_counter = 0;
        game->tiles.enemy.current_frame = (game->tiles.enemy.current_frame + 1) % ENEMY_ANIM_FRAMES;
    }
}

void    free_enemy_images(t_game *game)
{
    int i;

    i = 0;
    while (i < ENEMY_ANIM_FRAMES)
        mlx_destroy_image(game->mlx_ptr, game->tiles.enemy.frames[i++]);
}