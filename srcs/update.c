/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 11:13:25 by crea              #+#    #+#             */
/*   Updated: 2024/03/30 23:16:44 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	game_update(t_game *game)
{
	if (current_timestamp() - game->powerup.time >= THE_D_BURNS)
	{
		game->powerup.the_d = false;
		game->powerup.time = 0;
		//ft_printf(RUN_OUT);
	}
	update_animations(game);
	enemy_patrol(game);
	return (0);
}