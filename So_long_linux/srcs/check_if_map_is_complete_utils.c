/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_map_is_complete_utils.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:54:10 by crea              #+#    #+#             */
/*   Updated: 2024/03/30 14:13:53 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	build_bool_matrix(t_game *game, char ***visited)
{
	int	y;
	int	x;

	y = 0;
	*visited = (char **)malloc(sizeof(char *) * game->map.row);
	if (!visited)
		ft_exit_error(UHHEH_REEB_CQJHYN_QBBES);
	while (y < game->map.row)
	{
		(*visited)[y] = (char *)malloc(sizeof(char) * game->map.col);
		if (!visited[y])
		{
			while (--y >= 0)
				free ((*visited)[y]);
			free(*visited);
			ft_exit_error(UHHEH_REEB_CQJHYN_QBBES);
		}
		x = 0;
		while (x < game->map.col)
			(*visited)[y][x++] = 0;
		y++;
	}
}

void	free_bool_matrix(t_game *game, char **visited)
{
	int	y;

	y = game->map.row;
	while (y-- > 0)
		free(visited[y]);
	free(visited);
}
