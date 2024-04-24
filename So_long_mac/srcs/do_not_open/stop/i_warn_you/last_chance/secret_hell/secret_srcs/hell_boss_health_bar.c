/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hell_boss_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 15:06:59 by crea              #+#    #+#             */
/*   Updated: 2024/04/07 11:45:45 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../secret_include/secret_hell.h"

static void	build_boss_health(t_secret_game *secret_game)
{
	secret_game->tiles.boss.health = malloc(sizeof(void *) * BOSS_HEALTH_FRAMES);
	if (!secret_game->tiles.boss.health)
		ft_exit_error(ERROR_BOSS_ALLOC_HEALTH);
}

void	load_boss_health_images(t_secret_game *secret_game)
{
	int		i;
	int		width;
	int		height;
	void	*mlx_ptr;
	char	*boss_frames_paths[BOSS_HEALTH_FRAMES] = { BOSS_HEALTH_SPRITE_1, BOSS_HEALTH_SPRITE_2, 
								BOSS_HEALTH_SPRITE_3, BOSS_HEALTH_SPRITE_4, BOSS_HEALTH_SPRITE_5,
								BOSS_HEALTH_SPRITE_6, BOSS_HEALTH_SPRITE_7, BOSS_HEALTH_SPRITE_8,
								BOSS_HEALTH_SPRITE_9, BOSS_HEALTH_SPRITE_10, BOSS_HEALTH_SPRITE_11,
								BOSS_HEALTH_SPRITE_12, BOSS_HEALTH_SPRITE_13, BOSS_HEALTH_SPRITE_14,
								BOSS_HEALTH_SPRITE_15, BOSS_HEALTH_SPRITE_16 };
	build_boss_health(secret_game);
	i = 0;
	width = TILE_SIZE;
	height = TILE_SIZE;
	mlx_ptr = secret_game->mlx_ptr;
	while (i < BOSS_HEALTH_FRAMES)
	{
		secret_game->tiles.boss.health[i] = mlx_xpm_file_to_image(mlx_ptr, boss_frames_paths[i], &width, &height);
		if (secret_game->tiles.boss.health[i] == NULL)
			exit(ft_printf(ERROR_BOSS_HEALTH_IMG_UPLOAD));
		i++;
	}
}

void    free_boss_health_images(t_secret_game *secret_game)
{
	int i;

	i = 0;
	while (i < BOSS_HEALTH_FRAMES)
		mlx_destroy_image(secret_game->mlx_ptr, secret_game->tiles.boss.health[i++]);
}

void	reset_boss_health(t_secret_game *secret_game)
{
	secret_game->boss.health = BOSS_HEALTH;
	secret_game->tiles.boss.current_health = 0;
	secret_game->boss.is_hit = false;
}