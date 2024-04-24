/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   secret_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 16:53:06 by crea              #+#    #+#             */
/*   Updated: 2024/04/09 21:41:21 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../secret_include/secret_hell.h"

void    escape_hell(t_game *game)
{
	t_secret_game	secret_game;

	secret_game = init_secret_game();
	secret_game.game = game;
	secret_game.mlx_ptr = game->mlx_ptr;
	secret_game.mlx_win = game->mlx_win;
	secret_game.game->moves = 0;
    secret_game.game->map.collect = 0;
	ft_printf(ESCAPED);
	init_secret_hell(&secret_game);
	secret_main(&secret_game);
	return ;
}

void	secret_main(t_secret_game *secret_game)
{
	if (secret_game->pause == false)
	{
		mlx_hook(secret_game->mlx_win, DESTROY_WIN_CLIENT_MSG, 0, secret_close_game, secret_game);
		mlx_key_hook(secret_game->mlx_win, secret_key_press, secret_game);		
		mlx_loop_hook(secret_game->mlx_ptr, secret_game_update, secret_game);
		mlx_loop(secret_game->mlx_ptr);
	}
}

int	secret_game_update(t_secret_game *secret_game)
{
	long long	current;

	current = current_timestamp();
	if (current - secret_game->game->powerup.time >= THE_D_BURNS)
		depression_of_the_d(secret_game->game);
	if (current - secret_game->player.last_hit >= PLAYER_REGEN_TIME &&
		secret_game->player.is_hit)
		reset_player_health(secret_game);
	if (current - secret_game->boss.last_hit >= BOSS_REGEN_TIME &&
		secret_game->boss.is_hit && secret_game->boss.is_alive)
		reset_boss_health(secret_game);
	if (current - secret_game->boss.last_shot >= BOSS_WEAPON_RATIO)
		secret_game->boss.can_shoot = true;
	if (current - secret_game->boss.last_shot >= WEAPON_SELF_DESTROY)
		destroy_weapon(secret_game);
	if (secret_game->boss.is_alive)
		boss_patrol(secret_game);
	secret_update_animations(secret_game);
	return (0);
}

int	secret_key_press(int keycode, t_secret_game *secret_game)
{
	if (keycode == ESC)
	{
		ft_printf(SECRET_EARLY_GAME_CLOSE);
		secret_close_game(secret_game);
	}
	if (keycode == PAUSE)
	{
		secret_game->pause = true;
		secret_pause(secret_game);
	}
	else
		handle_secret_player_movement(secret_game, keycode);
	return (0);
}

void	init_secret_hell(t_secret_game *secret_game)
{
	change_map(secret_game);
	secret_init_sprites(secret_game);
	secret_cheat_init(secret_game);
}