/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:46:20 by crea              #+#    #+#             */
/*   Updated: 2024/04/09 21:51:47 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>
# include <time.h>
# include <../mlx/mlx.h>
# include "messages.h"
# include "outer_messages.h"
# include "keys.h"
# include "images.h"
# include "mechanics.h"
# include "../libft/include/libft.h"
# include "../ft_printf/include/ft_printf.h"

# define DISPLAY_NAME "So_longo!"

/* enum for display size */
typedef enum window
{
	WIDTH,
	HEIGHT
}	window;

/* enum for boolean var type */
typedef enum e_bool
{
	false = 0,
	true = 1
}	t_bool;

/* enum for map tiles symbols */
typedef enum map_tiles
{
	FLOOR = '0',
	WALL = '1',
	PLAYER = 'P',
	COLLECT = 'C',
	EXIT = 'E',
	ENEMY = 'N',
}	map_tiles;

/* struct for display size */
typedef struct s_display
{
	int	width;
	int	height;
}		t_display;

/* struct for player position axis */
typedef struct s_axis
{
	int		x;
	int		y;
	t_bool	facing_left;
}			t_axis;

/* struct for checking reachable collectables and exit */
typedef struct s_reachable
{
	int     collect_reachable;
	t_bool  exit_reachable;
}           t_reachable;

/* struct for enemy patrol */
typedef struct	s_enemy
{
	t_axis	enemy_pos;
	t_bool	alive;
	int		index;
}			t_enemy;

/* struct for player power ups */
typedef struct	s_powerup
{
	t_bool		the_d;
	long long	time;
}			t_powerup;

/* struct for wall animated tiles */
typedef struct	s_wall_anim_sprite
{
	void	*frames[WALL_ANIM_FRAMES];
	int		current_frame;
	int		anim_counter;
}			t_wall_anim_sprite;

/* struct for player animated tiles */
typedef struct	s_player_anim_sprite
{
	void	*frames[PLAYER_ANIM_FRAMES];
	int		current_frame;
	int		anim_counter;
}			t_player_anim_sprite;

/* struct for player d animated tiles */
typedef struct	s_player_d_anim_sprite
{
	void	*frames[PLAYER_ANIM_FRAMES];
	int		current_frame;
	int		anim_counter;
}			t_player_d_anim_sprite;

/* struct for inverted player animated tiles */
typedef struct	s_player_inv_anim_sprite
{
	void	*frames[PLAYER_ANIM_FRAMES];
	int		current_frame;
	int		anim_counter;
}			t_player_inv_anim_sprite;

/* struct for inverted player animated tiles */
typedef struct	s_player_d_inv_anim_sprite
{
	void	*frames[PLAYER_ANIM_FRAMES];
	int		current_frame;
	int		anim_counter;
}			t_player_d_inv_anim_sprite;

/* struct for exit animated tiles */
typedef struct	s_exit_anim_sprite
{
	void	*frames[EXIT_ANIM_FRAMES];
	int		current_frame;
	int		anim_counter;
}			t_exit_anim_sprite;

/* struct for collect animated tiles */
typedef struct	s_collect_anim_sprite
{
	void	*frames[COLLECT_ANIM_FRAMES];
	int		current_frame;
	int		anim_counter;
}			t_collect_anim_sprite;

/* struct for collect animated tiles */
typedef struct	s_enemy_anim_sprite
{
	void	*frames[ENEMY_ANIM_FRAMES];
	int		current_frame;
	int		anim_counter;
}			t_enemy_anim_sprite;

typedef struct	s_number_sprite
{
	void	**count;
}			t_number_sprite;

/* struct for all tiles & sprites specifics */
typedef struct s_tiles
{
	void						*floor;
	t_wall_anim_sprite			wall;
	t_player_anim_sprite		player;
	t_player_d_anim_sprite		player_d;
	t_player_inv_anim_sprite	player_inv;
	t_player_d_inv_anim_sprite	player_d_inv;
	t_collect_anim_sprite		collect;
	t_exit_anim_sprite			exit;
	t_enemy_anim_sprite			enemy;
	t_number_sprite				number;
	int							width;
	int							height;
	int							x;
	int							y;
}								t_tiles;

/* struct for all map specifics */
typedef struct s_map
{
	char		**matrix;
	int			row;
	int			col;
	int			collect;
	int			player;
	int			exit;
	int			enemies;
	int			enemy_index;
	int			enemy_target;
	int			enemies_alive;
	t_enemy		*enemy;
	t_reachable reachable;
	t_axis      player_pos;
	int			holes;
}				t_map;

/* struct for all game's specifics */
typedef struct s_game
{
	t_map		map;
	void		*mlx_ptr;
	void		*mlx_win;
	t_tiles		tiles;
	t_display	win;
	int			moves;
	t_bool		lose;
	t_bool		victory;
	t_bool		can_escape;
	t_bool		escaped;
	t_bool		secret_hell;
	t_powerup	powerup;
	long long	screenup;
}				t_game;

/* inline function to initialize the game map, tiles, player_pos & moves, and all checks */
static inline t_game    init_game(void)
{
	return ((t_game)
	{
		.map.matrix = NULL,
		.map.row = 0,
		.map.col = 0,
		.map.collect = 0,
		.map.player = 0,
		.map.exit = 0,
		.map.enemies = 0,
		.map.enemy_index = 0,
		.map.enemy_target = -1,
		.map.enemies_alive = 0,
		.map.reachable.collect_reachable = 0,
		.map.reachable.exit_reachable = false,
		.map.player_pos.facing_left = false,
		.map.holes = 0,
		.tiles.floor = NULL,
		.tiles.wall.current_frame = 0,
		.tiles.wall.anim_counter = 0,
		.tiles.player.current_frame = 0,
		.tiles.player.anim_counter = 0,
		.tiles.player_d.current_frame = 0,
		.tiles.player_d.anim_counter = 0,
		.tiles.player_inv.current_frame = 0,
		.tiles.player_inv.anim_counter = 0,
		.tiles.player_d_inv.current_frame = 0,
		.tiles.player_d_inv.anim_counter = 0,
		.tiles.collect.current_frame = 0,
		.tiles.collect.anim_counter = 0,
		.tiles.exit.current_frame = 0,
		.tiles.exit.anim_counter = 0,
		.tiles.enemy.current_frame = 0,
		.tiles.enemy.anim_counter = 0,
		.tiles.width = TILE_SIZE,
		.tiles.height = TILE_SIZE,
		.tiles.x = 0,
		.tiles.y = 0,
		.win.width = 0,
		.win.height = 0,
		.moves = 0,
		.lose = false,
		.victory = false,
		.can_escape = false,
		.escaped = false,
		.secret_hell = false,
		.powerup.the_d = false,
		.powerup.time = 0,
		.screenup = 0,
	});
}

/* map extention control */
int		check_map_ext(char *map_file);

/* get map */
void	get_map(t_game *game, char *map_file);
int		build_matrix(t_game *game, char *map_file);
int		check_matrix(t_game *game);

/* get map utils */
void	get_map_size(t_game *game, char *map_file);
void	get_map_col(t_game *game);
void	save_player_pos(t_game *game);
void	print_matrix(t_game *game);
void	printf_flood_matrix(t_game *game, char **visited);

/* map edges controls */
int		check_top_map(t_game *game);
int		check_bottom_map(t_game *game);
int		check_if_rect(t_game *game);
int		check_map_sides(t_game *game);
int		check_wrong_symb(t_game *game);

/* map internal control */
int		check_map_player(t_game *game);
int		check_map_exit(t_game *game);
int		check_map_collect(t_game *game);
int		check_map_enemy(t_game *game);
int		is_map_complete(t_game *game);

/* animation handler */
void	update_animations(t_game *game);
void	handle_animations(t_game *game);
void	*handle_diff_player_anim(t_game *game, char tile);

/* walls sprites animation */
void	load_wall_images(t_game *game);
void	handle_wall_anim(t_game *game);
void	free_wall_images(t_game *game);

/* player sprites animation */
void	load_player_images(t_game *game);
void	handle_player_anim(t_game *game);
void	free_player_images(t_game *game);

/* player sprites animation */
void	load_player_d_images(t_game *game);
void	handle_player_d_anim(t_game *game);
void	free_player_d_images(t_game *game);

/* player inv sprites animation */
void	load_player_inv_images(t_game *game);
void	handle_player_inv_anim(t_game *game);
void	free_player_inv_images(t_game *game);

/* player inv sprites animation */
void	load_player_d_inv_images(t_game *game);
void	handle_player_d_inv_anim(t_game *game);
void	free_player_d_inv_images(t_game *game);

/* collectable sprites animation */
void	load_collect_images(t_game *game);
void	handle_collect_anim(t_game *game);
void	free_collect_images(t_game *game);

/* exit sprites animation */
void	load_exit_images(t_game *game);
void	handle_exit_anim(t_game *game);
void	free_exit_images(t_game *game);

/* enemy sprites animation */
void	load_enemy_images(t_game *game);
void	handle_enemy_anim(t_game *game);
void	free_enemy_images(t_game *game);

/* number sprites */
void	load_number_images(t_game *game);
void	draw_text(t_game *game);
void    free_number_images(t_game *game);

/* sprites render */
void	init_sprites(t_game *game);
void	render_tiles(t_game *game, char tile);
void	draw_map(t_game *game);
void	free_images(t_game *game);

/* manage display */
void	manage_display(t_game *game);
void	get_win_size(t_game *game);
void	open_display(t_game *game);

/* player movement */
void	handle_key_event(t_game *game);
int		key_press(int keycode, t_game *game);
void	handle_player_movement(t_game *game, int keycode);
void	handle_movement_changes(t_game *game, int new_x, int new_y);
int		try_to_drill(t_game *game, int new_x, int new_y);

/* player movement utils */
int		is_valid_move(t_game *game, int new_x, int new_y, int keycode);
void	check_if_player_facing_left(t_game *game, int new_x);
void	update_player_pos(t_game *game, int new_x, int new_y);
void	update_collect_count(t_game *game, int new_x, int new_y);
void	check_if_win(t_game *game, int new_x, int new_y);

/* update */
int		game_update(t_game *game);

/* handle closure */
void	clean_matrix(t_game *game);
int		close_game(void *param);

/* game mechanics */
void	player_lose(t_game *game, char *reason);
void	exit_lose(t_game *game);
void	player_win(t_game *game);

/* game mechanics utils */
int 	random_range(unsigned int min, unsigned int max);
long long	current_timestamp(void);

/* enemy mechanics */
int		enemy_got_player(t_game *game, int new_x, int new_y);
void	enemy_patrol(t_game *game);
void	move_enemy(t_game *game);
void	update_enemy_pos(t_game *game, int new_x, int new_y);
void	self_destroy(t_game *game);

/* enemy mechanics utils */
void	build_enemy_arr(t_game *game);
void	save_enemy_pos(t_game *game);
int		is_valid_enemy_move(t_game *game, int new_x, int new_y);
void	free_enemy_arr(t_game *game);
void	handle_enemy(t_game *game);

/* player mechanics */
int		player_bump_enemy(t_game *game, int new_x, int new_y);
void	power_of_the_d(t_game *game);
void	depression_of_the_d(t_game *game);
void	destroy_enemy(t_game *game);

/* player mechanics utils */
void	get_enemy_target(t_game *game, int new_x, int new_y);
void	remove_enemy_from_matrix(t_game *game);

#endif