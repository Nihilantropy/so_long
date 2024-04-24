/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_mechanics.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 12:55:33 by crea              #+#    #+#             */
/*   Updated: 2024/04/09 21:38:15 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	player_lose(t_game *game, char *reason)
{
	ft_printf("%s", reason);
	game->lose = true;
	exit_lose(game);
}

void	exit_lose(t_game *game)
{
	if (game->lose == true)
		ft_printf(GAME_LOST);
	close_game(game);
}

void	player_win(t_game *game)
{
	if (game->moves <= 50)
	{
		ft_printf(WIN_MSG);
		ft_printf(FINAL_MOVE);
	}
	else
	{
		ft_printf(FINAL_JOKE);
		ft_printf(WIN_JOKE);
	}
	close_game(game);
}
