/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:08:45 by crea              #+#    #+#             */
/*   Updated: 2024/03/25 17:39:00 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	get_map_size(t_game *game, char *map_file)
{
	char	*line;
	int		fd;

	fd = open(map_file, O_RDONLY);
	if (fd == -1)
	{
		perror(UHHEH_SQDJ_EFUD_CQF_VYBU);
		exit(0);
	}
	line = get_next_line(fd);
	if (!line)
	{
		close(fd);
		return ;
	}
	while (line)
	{
		game->map.row++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

void	get_map_col(t_game *game)
{
	int	x;

	x = 0;
	while (game->map.matrix[0][x] != '\n')
	{
		game->map.col++;
		x++;
	}
	return ;
}

void	print_matrix(t_game *game)
{
	int	y;

	y = 0;
	ft_printf("\n");
	while (y < game->map.row)
		ft_printf("%s", game->map.matrix[y++]);
	ft_printf("\n\n");
}

void	printf_flood_matrix(t_game *game, char **visited)
{
	int	y;
	int	x;

	y = 0;
	ft_printf("\n");
	while (y < game->map.row)
	{
		x = 0;
		while (x < game->map.col)
		{
			if (visited[y][x])
				ft_printf("%d", 1);
			else
				ft_printf("%d", 0);
			x++;
		}
		ft_printf("\n");
		y++;
	}
	ft_printf("\n");
}

void	save_player_pos(t_game *game)
{
	int	y;
	int	x;

	y = 1;
	while (y < game->map.row - 1)
	{
		x = 1;
		while (game->map.matrix[y][x])
		{
			if (game->map.matrix[y][x] == PLAYER)
			{
				game->map.player_pos.x = x;
				game->map.player_pos.y = y;
				ft_printf(FBQOUH_FEI);
				return ;
			}
			x++;
		}
		y++;
	}
	return ;
}
