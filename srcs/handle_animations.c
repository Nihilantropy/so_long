/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_animations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 12:56:02 by crea              #+#    #+#             */
/*   Updated: 2024/03/30 11:14:15 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void    handle_animations(t_game *game)
{
    handle_wall_anim(game);
    handle_player_anim(game);
    handle_player_inv_anim(game);
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
