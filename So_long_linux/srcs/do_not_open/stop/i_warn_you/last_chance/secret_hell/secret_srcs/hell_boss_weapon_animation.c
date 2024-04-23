/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hell_boss_weapon_animation.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 12:10:02 by crea              #+#    #+#             */
/*   Updated: 2024/04/23 15:07:16 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../secret_include/secret_hell.h"

static void	build_boss_weapon_frame(t_secret_game *secret_game)
{
	secret_game->tiles.boss.weapon_frames = malloc(sizeof(void *) * BOSS_WEAPON_FRAMES);
	if (!secret_game->tiles.boss.weapon_frames)
		ft_exit_error(UHHEH_REII_MUQFED_QBBES_VHQCU);
}

void	load_boss_weapon_images(t_secret_game *secret_game)
{
	int		i;
	int		width;
	int		height;
	char	*boss_weapon_frames_paths[BOSS_WEAPON_FRAMES] = { BOSS_WEAPON_SPRITE_1, BOSS_WEAPON_SPRITE_2, 
												BOSS_WEAPON_SPRITE_3, BOSS_WEAPON_SPRITE_4, BOSS_WEAPON_SPRITE_5,
												BOSS_WEAPON_SPRITE_6, BOSS_WEAPON_SPRITE_7, BOSS_WEAPON_SPRITE_8 };
	build_boss_weapon_frame(secret_game);
	i = 0;
	width = TILE_SIZE;
	height = TILE_SIZE;
	while (i < BOSS_WEAPON_FRAMES)
	{
		secret_game->tiles.boss.weapon_frames[i] = mlx_xpm_file_to_image(secret_game->mlx_ptr, boss_weapon_frames_paths[i], &width, &height);
		if (secret_game->tiles.boss.weapon_frames[i] == NULL)
			exit(ft_printf(UHHEH_REII_MUQFED_YCW_KFBEQT));
		i++;
	}
}

void	handle_boss_weapon_anim(t_secret_game *secret_game)
{
	if (secret_game->boss.is_alive)
	{
		secret_game->tiles.boss.weap_anim_counter++;
		if (secret_game->tiles.boss.weap_anim_counter >= FRAME_RATE / 2)
		{
			secret_game->tiles.boss.weap_anim_counter = 0;
			secret_game->tiles.boss.current_weap_frame = (secret_game->tiles.boss.current_weap_frame + 1) % BOSS_WEAPON_FRAMES;
		}
	}
}

void	free_boss_weapon_images(t_secret_game *secret_game)
{
	int i;

	i = 0;
	while (i < BOSS_WEAPON_FRAMES)
		mlx_destroy_image(secret_game->mlx_ptr, secret_game->tiles.boss.weapon_frames[i++]);
}