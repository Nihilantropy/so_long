/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_animation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 12:55:55 by crea              #+#    #+#             */
/*   Updated: 2024/03/29 12:55:56 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void load_exit_images(t_game *game)
{
    int i;
    int width;
    int height;
    char *exit_frames_paths[EXIT_ANIM_FRAMES] = { EXIT_SPRITE_FRAME_1, EXIT_SPRITE_FRAME_2, 
                            EXIT_SPRITE_FRAME_3, EXIT_SPRITE_FRAME_4,
                            EXIT_SPRITE_FRAME_5, EXIT_SPRITE_FRAME_6, EXIT_SPRITE_FRAME_7,
                            EXIT_SPRITE_FRAME_8, EXIT_SPRITE_FRAME_9, EXIT_SPRITE_FRAME_10 };

    i = 0;
    width = TILE_SIZE;
    height = TILE_SIZE;
    while (i < EXIT_ANIM_FRAMES)
    {
        game->tiles.exit.frames[i] = mlx_xpm_file_to_image(game->mlx_ptr, exit_frames_paths[i], &width, &height);
        if (game->tiles.exit.frames[i] == NULL)
            exit(ft_printf(UHHEH_UNYJ_YCW_KFBEQT));
        i++;
    }
}

void handle_exit_anim(t_game *game)
{
    game->tiles.exit.anim_counter++;
    if (game->tiles.exit.anim_counter >= FRAME_RATE / 2)
    {
        game->tiles.exit.anim_counter = 0;
        game->tiles.exit.current_frame = (game->tiles.exit.current_frame + 1) % EXIT_ANIM_FRAMES;
    }
}

void    free_exit_images(t_game *game)
{
    int i;

    i = 0;
    while (i < EXIT_ANIM_FRAMES)
        mlx_destroy_image(game->mlx_ptr, game->tiles.exit.frames[i++]);
}