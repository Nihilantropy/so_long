/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_health_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 22:42:05 by crea              #+#    #+#             */
/*   Updated: 2024/04/07 01:19:31 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../secret_include/secret_hell.h"

static void	build_player_health(t_secret_game *secret_game)
{
	secret_game->player.health_bar = malloc(sizeof(void *) * PLAYER_HEALTH_FRAMES);
	if (!secret_game->player.health_bar)
		ft_exit_error(UHHEH_FBQOUH_QBBES_XUQBJX);
}

void	load_player_health_images(t_secret_game *secret_game)
{
	int		i;
	int		width;
	int		height;
	void	*mlx_ptr;
	char	*player_frames_paths[PLAYER_HEALTH_FRAMES] = { PLAYER_HEALTH_SPRITE_1, PLAYER_HEALTH_SPRITE_2, 
								PLAYER_HEALTH_SPRITE_3, PLAYER_HEALTH_SPRITE_4 };
	build_player_health(secret_game);
	i = 0;
	width = TILE_SIZE;
	height = TILE_SIZE;
	mlx_ptr = secret_game->mlx_ptr;
	while (i < PLAYER_HEALTH_FRAMES)
	{
		secret_game->player.health_bar[i] = mlx_xpm_file_to_image(mlx_ptr, player_frames_paths[i], &width, &height);
		if (secret_game->player.health_bar[i] == NULL)
			exit(ft_printf(UHHEH_FBQOUH_XUQBJX_YCW_KFBEQT));
		i++;
	}
}

void    free_player_health_images(t_secret_game *secret_game)
{
	int i;

	i = 0;
	while (i < PLAYER_HEALTH_FRAMES)
		mlx_destroy_image(secret_game->mlx_ptr, secret_game->player.health_bar[i++]);
}

void	reset_player_health(t_secret_game *secret_game)
{
	secret_game->player.health = PLAYER_HEALTH;
	secret_game->player.current_health = 0;
	secret_game->player.is_hit = false;
}