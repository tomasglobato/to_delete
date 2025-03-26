/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_path_validation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togomes- <togomes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 14:18:39 by togomes-          #+#    #+#             */
/*   Updated: 2025/03/25 23:23:44 by togomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
/*
void	valid_path(char **map, int x, int y, t_game *game)
{
	if (x <= 0 || y <= 0 || y == game->height || x == game->width - 1 || map[y][x] == '1')
		return ;
	if (map[y][x] == 'v' || map[y][x] == '1' || map[y][x] == 'e')
		return ;
	if (map[y][x] == 'E')
	{
		map[y][x] = 'e';
		return ;
	}
	if (map[y][x] != '1' && map[y][x] != 'e')
		map[y][x] = 'v';
	valid_path(map, x + 1, y, game);
	valid_path(map, x - 1, y, game);
	valid_path(map, x, y + 1, game);
	valid_path(map, x, y - 1, game);
}

int	path_checker(char **map, t_game *game)
{
	int y;
	int x;

	y = -1;
	while (++y < game->height)
	{
		x = -1;
		while (++x < game->width)
		{
			if (map[y][x] != '1' && map[y][x] != '0' && map[y][x] != 'v' && map[y][x] != 'e')
				return (1);
		}
	}
	return (0);
}

int path(t_game *game)
{
	char **map;
	int y;

	map = malloc(sizeof(char *) * (game->height + 1));
	if (!map)
	{
		//ft_free(game);
		return (0);
	}
	y = -1;
	while (game->map[++y])
		map[y] = ft_strdup(game->map[y]);
	valid_path(map, game->player_x, game->player_y, game);
	return (path_checker(map, game));
}*/
