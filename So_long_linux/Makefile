NAME		= so_long

SECRET_NAME	= so_longo

SOLONG_DIR	= ./srcs
SOLONG_HEAD	= ./include

SECRET_HEAD = ./srcs/do_not_open/stop/i_warn_you/last_chance/secret_hell/secret_include
SECRET_DIR	= ./srcs/do_not_open/stop/i_warn_you/last_chance/secret_hell/secret_srcs

SRCS		= main.c check_map_extention.c get_map.c get_map_utils.c check_map_edges.c check_map_interior.c \
				check_if_map_is_complete.c check_if_map_is_complete_utils.c manage_display.c render_map.c player_movement.c \
				player_movement_utils.c handle_closure.c handle_animations.c wall_animation.c player_animation.c player_inv_animation.c \
				collect_animation.c exit_animation.c enemy_animation.c game_mechanics.c game_mechanics_utils.c enemy_mechanics.c enemy_mechanics_utils.c \
				update.c player_mechanics.c player_mechanics_utils.c player_d_animation.c player_d_inv_animation.c number_sprites.c
						
SECRET_SRCS	= congratulation.c secret_main.c modify_hell.c secret_player_movement.c secret_player_movement_utils.c \
				secret_render_map.c secret_handle_animations.c secret_handle_closure.c hell_boss_health_bar.c hell_boss_animation.c hell_boss_mechanics.c \
				hell_boss_mechanics_utils.c hell_boss_movement.c hell_boss_movement_utils.c player_health_bar.c secret_key_cheat.c secret_pause.c \
				hell_boss_weapon_animation.c secret_game_mechanics.c

OBJS		= $(patsubst %.c, $(SOLONG_DIR)/%.o, $(SRCS))

SECRET_OBJS	= $(patsubst %.c, $(SECRET_DIR)/%.o, $(SECRET_SRCS))

LIBFT_DIR	= ./libft
LIBFT		= libft.a

PRINTF_DIR	= ./ft_printf
PRINTF_LIB	= libft_printf.a

MLX_DIR		= ./
MLX_LIB		= libmlx.a

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
RM = rm -f

# Include directory for header files
INC 		= -I$(SOLONG_HEAD) -I$(LIBFT_DIR) -I$(PRINTF_DIR) -I$(MLX_DIR)

SECRET_INC	= -I$(SOLONG_HEAD) -I$(SECRET_HEAD) -I$(LIBFT_DIR) -I$(PRINTF_DIR) -I$(MLX_DIR)

# Compilation rule for the program
$(NAME): $(LIBFT) $(PRINTF_LIB) $(MLX_LIB) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lft_printf -L$(MLX_DIR) -lmlx -lX11 -lXext -lm -o $(NAME)

$(SECRET_NAME): $(LIBFT) $(PRINTF_LIB) $(MLX_LIB) $(OBJS) $(SECRET_OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(SECRET_OBJS) -L$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lft_printf -L$(MLX_DIR) -lmlx -lX11 -lXext -lm -o $(SECRET_NAME)


# Rule to compile object files
$(SOLONG_DIR)/%.o: $(SOLONG_DIR)/%.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(SECRET_DIR)/%.o: $(SECRET_DIR)/%.c
	$(CC) $(CFLAGS) $(SECRET_INC) -c $< -o $@

# Rule to make libft
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# Rule to make libft_printf
$(PRINTF_LIB):
	$(MAKE) -C $(PRINTF_DIR)

all:		$(NAME)

secret_all:	$(SECRET_NAME)

clean:
			$(RM) $(OBJS) $(SECRET_OBJS)
			$(MAKE) -C $(LIBFT_DIR) clean
			$(MAKE) -C $(PRINTF_DIR) clean

fclean:		clean
			$(RM) $(NAME) $(SECRET_NAME)
			$(MAKE) -C $(LIBFT_DIR) fclean
			$(MAKE) -C $(PRINTF_DIR) fclean

re:			fclean all

rec:		clean all

# Run this from another terminal while game is running
test: 		
			valgrind --leak-check=full ./so_long map/map00.ber

secret:		huluqb_iushuji secret_all xytu_iushuji

csecret:	clean secret

fsecret:	fclean secret

huluqb_iushuji:
	@./iushuji/huluqb_iushuji.sh
xytu_iushuji:
	@./iushuji/xytu_iushuji.sh

.PHONY:		all clean fclean re rec test secret csecret fsecret secret_all decript