/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hell_boss_animation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 19:32:18 by crea              #+#    #+#             */
/*   Updated: 2024/04/09 14:59:26 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../secret_include/secret_hell.h"

static void	build_boss_frame(t_secret_game *secret_game)
{
	int	i;

	i = 0;
	secret_game->tiles.boss.frames = malloc(sizeof(void *) * BOSS_ANIM_FRAMES);
	if (!secret_game->tiles.boss.frames)
		ft_exit_error(UHHEH_REII_QBBES_VHQCU);
}

void	load_boss_images(t_secret_game *secret_game)
{
	int		i;
	int		width;
	int		height;
	char	*boss_frames_paths[BOSS_ANIM_FRAMES] = { BOSS_SPRITE_FRAME_1, BOSS_SPRITE_FRAME_2, 
												BOSS_SPRITE_FRAME_3, BOSS_SPRITE_FRAME_4,
												BOSS_SPRITE_FRAME_5, BOSS_SPRITE_FRAME_6, 
												BOSS_SPRITE_FRAME_7, BOSS_SPRITE_FRAME_8 };
	build_boss_frame(secret_game);
	i = 0;
	width = TILE_SIZE;
	height = TILE_SIZE;
	while (i < BOSS_ANIM_FRAMES)
	{
		secret_game->tiles.boss.frames[i] = mlx_xpm_file_to_image(secret_game->mlx_ptr, boss_frames_paths[i], &width, &height);
		if (secret_game->tiles.boss.frames[i] == NULL)
			exit(ft_printf(UHHEH_REII_YCW_KFBEQT));
		i++;
	}
}

void handle_boss_anim(t_secret_game *secret_game)
{
	if (secret_game->boss.health > 1)
	{
		secret_game->tiles.boss.anim_counter++;
		if (secret_game->tiles.boss.anim_counter >= FRAME_RATE / 2)
		{
			secret_game->tiles.boss.anim_counter = 0;
			secret_game->tiles.boss.current_frame = (secret_game->tiles.boss.current_frame + 1) % (BOSS_ANIM_FRAMES - 1);
		}
	}
}

void    free_boss_images(t_secret_game *secret_game)
{
	int i;

	i = 0;
	while (i < BOSS_ANIM_FRAMES)
		mlx_destroy_image(secret_game->mlx_ptr, secret_game->tiles.boss.frames[i++]);
}