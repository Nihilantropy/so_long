/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   secret_key_cheat.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 12:09:42 by crea              #+#    #+#             */
/*   Updated: 2024/04/09 21:50:17 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../secret_include/secret_hell.h"

void	secret_cheat_init(t_secret_game *secret_game)
{
	secret_game->cheat = malloc(sizeof(char) * ft_strlen(CHEAT) + 1);
	if (!secret_game->cheat)
		ft_exit_error(UHHEH_SXUQJ_QBBES);
	ft_strlcpy(secret_game->cheat, CHEAT, (ft_strlen(CHEAT) + 1));
}

void	secret_key_close(t_secret_game *secret_game, int keycode)
{
	if (keycode == ESC)
	{
		ft_printf(IUSHUJ_UQHBO_WQCU_SBEIU);
		secret_close_game(secret_game);
	}
}

int	secret_cheat(t_secret_game *secret_game, int keycode)
{
	secret_key_close(secret_game, keycode);
	if (KEY_TO_CHAR(keycode) == secret_game->cheat[secret_game->cheat_index])
	{
		secret_game->cheat_index++;
		if (secret_game->cheat_index == ft_strlen(secret_game->cheat))
		{
			ft_printf(SXUQJ_TEDU);
			kill_boss(secret_game);
			secret_game->pause = false;
			secret_main(secret_game);
		}
	}
	else if (keycode == PAUSE)
	{
		secret_game->cheat_index = 0;
		secret_game->pause = false;
		secret_main(secret_game);
	}
	else
	{
		ft_printf(SXUQJ_UHHEH);
    	secret_game->cheat_index = 0;
	}
	return (0);
}

void	kill_boss(t_secret_game *secret_game)
{
	secret_game->boss.health = 0;
	secret_game->boss.is_alive = false;
	secret_game->tiles.boss.current_frame = BOSS_ANIM_FRAMES - 1;
	secret_game->tiles.boss.current_health = BOSS_HEALTH_FRAMES - 1;
	secret_game->cheat_done = true;
}