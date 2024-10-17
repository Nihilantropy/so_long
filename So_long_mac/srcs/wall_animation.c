/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_animation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 12:56:33 by crea              #+#    #+#             */
/*   Updated: 2024/03/29 12:56:33 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void load_wall_images(t_game *game)
{
    int i;
    int width;
    int height;
    char *wall_frames_paths[WALL_ANIM_FRAMES] = { WALL_SPRITE_FRAME_1, WALL_SPRITE_FRAME_2, 
                            WALL_SPRITE_FRAME_3, WALL_SPRITE_FRAME_4,
                            WALL_SPRITE_FRAME_5, WALL_SPRITE_FRAME_6, WALL_SPRITE_FRAME_7,
                            WALL_SPRITE_FRAME_8 };

    i = 0;
    width = TILE_SIZE;
    height = TILE_SIZE;
    while (i < WALL_ANIM_FRAMES)
    {
        game->tiles.wall.frames[i] = mlx_xpm_file_to_image(game->mlx_ptr, wall_frames_paths[i], &width, &height);
        if (game->tiles.wall.frames[i] == NULL)
            exit(ft_printf(UHHEH_MQBB_YCW_KFBEQT));
        i++;
    }
}

void handle_wall_anim(t_game *game)
{
    game->tiles.wall.anim_counter++;
    if (game->tiles.wall.anim_counter >= FRAME_RATE / 2)
    {
        game->tiles.wall.anim_counter = 0;
        game->tiles.wall.current_frame = (game->tiles.wall.current_frame + 1) % WALL_ANIM_FRAMES;
    }
}

void    free_wall_images(t_game *game)
{
    int i;

    i = 0;
    while (i < WALL_ANIM_FRAMES)
        mlx_destroy_image(game->mlx_ptr, game->tiles.wall.frames[i++]);
}