#include "../include/so_long.h"

static void	build_number_img_array(t_game *game)
{
	game->tiles.number.count = malloc(sizeof(t_number_sprite) * 10);
	if (!game->tiles.number.count)
		ft_exit_error(UHHEH_DKCRUH_YCW_QBBES);

}

void	load_number_images(t_game *game)
{
	int		i;
	int		width;
	int		height;
	build_number_img_array(game);
	char	*number_sprite_paths[10] = { NUMBER_0_SPIRTE, NUMBER_1_SPIRTE,
										NUMBER_2_SPIRTE, NUMBER_3_SPIRTE, 
										NUMBER_4_SPIRTE, NUMBER_5_SPIRTE,
										NUMBER_6_SPIRTE, NUMBER_7_SPIRTE,
										NUMBER_8_SPIRTE, NUMBER_9_SPIRTE };
	i = 0;
	width = TILE_SIZE;
	height = TILE_SIZE;
	while (i < 10)
	{
		game->tiles.number.count[i] = mlx_xpm_file_to_image(game->mlx_ptr, number_sprite_paths[i], &width, &height);
		if (game->tiles.number.count[i] == NULL)
			ft_exit_error(UHHEH_DKCRUH_YCW_KFBEQT);
		i++;
	}
}

void	draw_text(t_game *game)
{
	char	*str;
	int		i;
	int		x_offset;
	int		x;

	str = ft_itoa(game->moves);
	i = 0;
	x_offset = 0;
	x = 10;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			if (TILE_SIZE > x_offset)
				x_offset = TILE_SIZE;
			x += x_offset + 5;
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
									game->tiles.number.count[str[i] - '0'], x, 5);
			x_offset += TILE_SIZE / 10;
		}
		i++;
	}
	free(str);
}

void    free_number_images(t_game *game)
{
	int i;

	i = 0;
	while (i < 10)
		mlx_destroy_image(game->mlx_ptr, game->tiles.number.count[i++]);
}
