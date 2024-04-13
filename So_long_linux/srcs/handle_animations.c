/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_animations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 12:56:02 by crea              #+#    #+#             */
/*   Updated: 2024/03/30 22:29:06 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void    handle_animations(t_game *game)
{
    handle_wall_anim(game);
    handle_player_anim(game);
	handle_player_d_anim(game);
    handle_player_inv_anim(game);
	handle_player_d_inv_anim(game);
    handle_collect_anim(game);
    handle_exit_anim(game);
	handle_enemy_anim(game);
}

void	update_animations(t_game *game)
{
    handle_animations(game);
    draw_map(game);
    usleep(FRAME_TIME_US);
	return ;
}

void	*handle_diff_player_anim(t_game *game, char tile)
{
	void	*image;

	image = NULL;
	if (tile == PLAYER && game->map.player_pos.facing_left && !game->powerup.the_d)
        image = game->tiles.player_inv.frames[game->tiles.player_inv.current_frame];
	else if (tile == PLAYER && !game->map.player_pos.facing_left && !game->powerup.the_d)
        image = game->tiles.player.frames[game->tiles.player.current_frame];
	else if (tile == PLAYER && game->map.player_pos.facing_left && game->powerup.the_d)
        image = game->tiles.player_d_inv.frames[game->tiles.player_d_inv.current_frame];
	else if (tile == PLAYER && !game->map.player_pos.facing_left && game->powerup.the_d)
        image = game->tiles.player_d.frames[game->tiles.player_d.current_frame];
	return (image);
}
