#!/bin/bash

script_dir="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

player_movement_file="$script_dir/../srcs/player_movement.c"

so_long_file="$script_dir/../include/so_long.h"

update_file="$script_dir/../srcs/update.c"

# Rimuovi gli eventuali file di backup generati da sed
find "$player_movement_file" -name "*.*~" -delete
find "$so_long_file" -name "*.*~" -delete
find "$update_file" -name "*.*~" -delete

# Sostituisci i testi utilizzando sed senza creare file di backup
sed -i 's/SECRET_LOCKED/SECRET_UNLOCKED/g' "$player_movement_file"

sed -i '/#endif/i\
void escape_hell(t_game *game);\
\
int congratulation(t_game *game);\
\
' "$so_long_file"

sed -i '/if (current_timestamp() - game->powerup.time >= THE_D_BURNS)/i\
        if (game->escaped)\
                mlx_loop_hook(game->mlx_ptr, congratulation, game);\
        if (game->secret_hell)\
                escape_hell(game);\
' "$update_file"
