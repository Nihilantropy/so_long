/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 11:13:25 by crea              #+#    #+#             */
/*   Updated: 2024/04/09 21:51:51 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	game_update(t_game *game)
{
	if (current_timestamp() - game->powerup.time >= THE_D_BURNS)
		depression_of_the_d(game);
	update_animations(game);
	enemy_patrol(game);
	return (0);
}