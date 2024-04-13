#!/bin/bash

script_dir="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

player_movement_file="$script_dir/../srcs/player_movement.c"

so_long_file="$script_dir/../include/so_long.h"

update_file="$script_dir/../srcs/update.c"

sed -i '' 's/SECRET_UNLOCKED/SECRET_LOCKED/g' "$player_movement_file"

sed -i '' '/void escape_hell(t_game \*game);/,+1d' "$so_long_file"
sed -i '' '/int congratulation(t_game \*game);/,+1d' "$so_long_file"

sed -i '' '/if (game->escaped)/d' "$update_file"
sed -i '' '/mlx_loop_hook(game->mlx_ptr, congratulation, game);/d' "$update_file"
sed -i '' '/if (game->secret_hell)/d' "$update_file"
sed -i '' '/escape_hell(game);/d' "$update_file"