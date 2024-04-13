/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   secret_handle_animations.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 19:20:31 by crea              #+#    #+#             */
/*   Updated: 2024/04/08 12:49:19 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../secret_include/secret_hell.h"

static void    secret_handle_animations(t_secret_game *secret_game)
{
    handle_wall_anim(secret_game->game);
    handle_player_anim(secret_game->game);
	handle_player_d_anim(secret_game->game);
    handle_player_inv_anim(secret_game->game);
	handle_player_d_inv_anim(secret_game->game);
    handle_collect_anim(secret_game->game);
    handle_exit_anim(secret_game->game);
	handle_enemy_anim(secret_game->game);
	handle_boss_anim(secret_game);
	handle_boss_weapon_anim(secret_game);
}

void	secret_update_animations(t_secret_game *secret_game)
{
    secret_handle_animations(secret_game);
    secret_draw_map(secret_game);
    usleep(FRAME_TIME_US);
	return ;
}