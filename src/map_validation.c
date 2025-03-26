/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togomes- <togomes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 21:29:55 by togomes-          #+#    #+#             */
/*   Updated: 2025/03/26 21:42:13 by togomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	count_lines_and_columns(char **map, t_game *game)
{
	int	y;
	int	expected_columns;
	int	x;

	if (map == NULL || map[0] == NULL)
		map_error("The map is empty!\n");
	expected_columns = -1;
	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
			x++;
		if (expected_columns == -1)
			expected_columns = x;
		else if (expected_columns != x)
			map_error("The columns are not the same length!\n");
		y++;
	}
	game->width = expected_columns;
	game->height = y;
}

int		read_map_malloc(t_game *game, char *filename)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (1);
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		game->height++;
	}
	if (line)
		free(line);
	if (!game->height)
		return (1);
	game->map = malloc(sizeof(char *) * (game->height + 1));
	if (!game->map)
	{
		ft_free(game);
		return (1);
	}
	close(fd);
	return (0);
}

//char	**read_map(const char *filename)
int		read_map(t_game *game, char *filename)
{
	int		fd;
	int		i;
	//char	**map;
	//char	*line;
	//int		line_count;

	//i = 0;
	//line_count = 0;
	if (read_map_malloc(game, filename))
		return (ft_printf("Error\nMap doesn't exist\n"));
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (ft_printf("Error\nInvalid map file!\n"));
	i = 0;
	while (i <= game->height)
	{
		game->map[i] = get_next_line(fd);
		i++;
	}
	i = 0;
	close (fd);
	game->width = ft_strlen(game->map[0] - 1);
	return (0);
}
	/*while ((line = get_next_line(fd)) != NULL)
	{
		if (line[strlen(line) - 1] == '\n')
			line[strlen(line) - 1] = '\0';
		line_count++;
		free(line);
	}
	close(fd);
	map = malloc(sizeof(char *) * (line_count + 1));
	if (!map)
		return (NULL);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		input_error("Map doesn't exist1\n");
		return (NULL);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		if (line[strlen(line) - 1] == '\n')
			line[strlen(line) - 1] = '\0';
		map[i] = ft_strdup(line);
		free(line);
		i++;
	}
	map[i] = NULL;
	close(fd);
	return (map);
}*/

int	check_map_arg(char *map_name)
{
	int	len;

	len = strlen(map_name);
	if (map_name[len - 5] == '/')
		return (1);
	if (len > 3 && map_name[len - 1] == 'r' && map_name[len - 2] == 'e' && map_name[len - 3] == 'b' && map_name[len - 4] == '.')
		return (0);
	return (1);
}

int	check_map(char *map_name)
{
	size_t	i;

	i = ft_strlen(map_name) - 1;
	if (i > 4 && map_name[i] == 'r' && map_name[i - 1] == 'e' && map_name[i - 2] == 'b' && map_name[i - 3] == '.')
		return (0);
	return (1);
}
