/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   secret_handle_closure.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 19:16:14 by crea              #+#    #+#             */
/*   Updated: 2024/04/05 18:19:47 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../secret_include/secret_hell.h"

int	secret_close_game(void *param)
{
	t_secret_game	*secret_game;

	secret_game = param;
	mlx_clear_window(secret_game->mlx_ptr, secret_game->mlx_win);
	secret_free_images(secret_game);
	clean_matrix(secret_game->game);
	if (secret_game->game->map.enemies > 0)
		free_enemy_arr(secret_game->game);
	mlx_destroy_window(secret_game->mlx_ptr, secret_game->mlx_win);
	exit (0);
}
