/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   congratulation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 00:03:04 by crea              #+#    #+#             */
/*   Updated: 2024/04/07 21:54:11 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../secret_include/secret_hell.h"

static int	secret_early_close(t_game *game, int keycode);

int	congratulation(t_game *game)
{
	int len;
	int x;
	int y;
	
	len = ft_strlen(UDJUHYDW_IUSHUJ_XUBB);
	x = (game->win.width - (len * 10)) / 2;
	y = game->win.height / 2;
	mlx_hook(game->mlx_win, DESTROY_WIN_CLIENT_MSG, 0, secret_close_game, game);
	mlx_key_hook(game->mlx_win, secret_early_close, game);
	mlx_clear_window(game->mlx_ptr, game->mlx_win);
	if (game->map.row <= 7 || game->map.col <= 15)
		ft_exit_error(UHHEH_CQF_IYPU);
	if (game->screenup >= CONGRATS)
	{
		game->escaped = false;
		game->secret_hell = true;
		game_update(game);
		return (0);
	}
	else
		mlx_string_put(game->mlx_ptr, game->mlx_win, x, y, 0xFFFFFF, UDJUHYDW_IUSHUJ_XUBB);
	game->screenup++;
	return (1);
}

static int	secret_early_close(t_game *game, int keycode)
{
	if (keycode == ESC)
		close_game(game);
	return (0);
}