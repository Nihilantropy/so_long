/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_d_inv_animation.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 21:53:49 by crea              #+#    #+#             */
/*   Updated: 2024/03/30 22:11:09 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void load_player_d_inv_images(t_game *game)
{
    int i;
    int width;
    int height;
    char *player_frames_paths[PLAYER_ANIM_FRAMES] = { PLAYER_D_INV_SPRITE_FRAME_1, PLAYER_D_INV_SPRITE_FRAME_2, 
                            PLAYER_D_INV_SPRITE_FRAME_3, PLAYER_D_INV_SPRITE_FRAME_4,
                            PLAYER_D_INV_SPRITE_FRAME_5, PLAYER_D_INV_SPRITE_FRAME_6, 
                            PLAYER_D_INV_SPRITE_FRAME_7, PLAYER_D_INV_SPRITE_FRAME_8 };

    i = 0;
    width = TILE_SIZE;
    height = TILE_SIZE;
    while (i < PLAYER_ANIM_FRAMES)
    {
        game->tiles.player_d_inv.frames[i] = mlx_xpm_file_to_image(game->mlx_ptr, player_frames_paths[i], &width, &height);
        if (game->tiles.player_d_inv.frames[i] == NULL)
            exit(ft_printf(UHHEH_FBQOUH_T_YDL_YCW_KFBEQT));
        i++;
    }
}

void handle_player_d_inv_anim(t_game *game)
{
    game->tiles.player_d_inv.anim_counter++;
    if (game->tiles.player_d_inv.anim_counter >= FRAME_RATE / 2)
    {
        game->tiles.player_d_inv.anim_counter = 0;
        game->tiles.player_d_inv.current_frame = (game->tiles.player_d_inv.current_frame + 1) % PLAYER_ANIM_FRAMES;
    }
}

void    free_player_d_inv_images(t_game *game)
{
    int i;

    i = 0;
    while (i < PLAYER_ANIM_FRAMES)
        mlx_destroy_image(game->mlx_ptr, game->tiles.player_d_inv.frames[i++]);
}