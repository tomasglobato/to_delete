/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togomes- <togomes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 13:01:13 by togomes-          #+#    #+#             */
/*   Updated: 2025/03/26 21:56:04 by togomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_free_map(t_game *game)
{
    int i;

    i = 0;
    while (i < game->height)
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
	free(game);
}

void	ft_free_textures(t_game *game)
{
	if (game->wall)
	{
		mlx_destroy_image(game->mlx, game->wall);
		free(game->wall);
	}
	if (game->background)
	{
		mlx_destroy_image(game->mlx, game->background);
		free(game->background);
	}
	if (game->collectible)
	{
		mlx_destroy_image(game->mlx, game->collectible);
		free(game->collectible);
	}
	if (game->exit)
	{
		mlx_destroy_image(game->mlx, game->exit);
		free(game->exit);
	}
	if (game->player)
	{
		mlx_destroy_image(game->mlx, game->player);
		free(game->player);
	}
}

int    ft_free(t_game *game)
{
    if (!game)
		return (0);
    if (game->map)
		ft_free_map(game);
	if (game->wall || game->background || game->collectible || game->exit || game->player)
		ft_free_textures(game);
	/*if (game->player_x)
		free(game->player_x);
	if (game->player_y)
		free(game->player_y);*/
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
		mlx_destroy_display(game->mlx);
	free (game->mlx);
	free(game);
	return (0);
}


void	draw_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y] != NULL)
	{
		x = 0;
		while (game->map[y][x] != '\0')
		{
			if (game->map[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->wall, x * TILE_SIZE, y * TILE_SIZE);
			else if (game->map[y][x] == '0')
				mlx_put_image_to_window(game->mlx, game->win, game->background, x * TILE_SIZE, y * TILE_SIZE);
			else if (game->map[y][x] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->collectible, x * TILE_SIZE, y * TILE_SIZE);
			else if (game->map[y][x] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->exit, x * TILE_SIZE, y * TILE_SIZE);
			else if (game->map[y][x] == 'P')
				mlx_put_image_to_window(game->mlx, game->win, game->player, x * TILE_SIZE, y * TILE_SIZE);
			x++;
		}
		y++;
	}
}


void	load_map(t_game *game)
{
	game->wall = mlx_xpm_file_to_image(game->mlx, "./textures/wall.xpm", &game->width, &game->height);
	game->background = mlx_xpm_file_to_image(game->mlx, "./textures/background.xpm", &game->width, &game->height);
	game->collectible = mlx_xpm_file_to_image(game->mlx, "./textures/collectible.xpm", &game->width, &game->height);
	game->exit = mlx_xpm_file_to_image(game->mlx, "./textures/exit.xpm", &game->width, &game->height);
	game->player = mlx_xpm_file_to_image(game->mlx, "./textures/player.xpm", &game->width, &game->height);
	if (!game->wall || !game->background || !game->collectible || !game->exit || !game->player)
	{
		mlx_destroy_window(game->mlx, game->win);
		map_error("Failed to load game!\n");
		exit (1);
	}
	initialize_player_position(game);
}

int map_validation(char **map, t_game *game)
{
	int count_player;
	int count_exit;
	int x;
	int y;

	y = 0;
	count_player = 0;
	count_exit = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0' && map[y][x] != '\n')
		{
			if (map[y][x] != '1' && map[y][x] != '0' && map[y][x] != 'C' && map[y][x] != 'E' && map[y][x] != 'P')
				map_error("Invalid character in map.\n");
			if (map[y][x] == 'P')
				count_player++;
			else if (map[y][x] == 'E')
				count_exit++;
			else if (map[y][x] == 'C')
				game->total_collectibles++;
			if (map[y][x] != '1' && (y == 0 || y == game->height - 1 || x == 0 || x == game->width - 1))
				map_error("Map is not surrounded by walls!\n");
			if (map[y][x] != '1' && map[y][x] != '0' && map[y][x] != 'C' && map[y][x] != 'E' && map[y][x] != 'P')
				map_error("Map contains invalid characters!\n");
			x++;
		}
		y++;
	}
	if (x == y)
		map_error("Map is not rectangular!\n");
	if (count_player != 1)
		map_error("Map must contain exactly one player!\n");
	if (count_exit != 1)
		map_error("Map must contain exactly one exit!\n");
	if (game->total_collectibles < 1)
		map_error("Map must contain at least one collectible!\n");
	return (1);
}


int	close_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	ft_free(game);
	exit(0);
	return (0);
}

void	call_map_validations(char **map_path, t_game *game)
{
	//if (path(game))
	//	map_error("Path to exit is blocked!\n");
	count_lines_and_columns(map_path, game);
	if (!map_validation(map_path, game))
		map_error("Map is not valid!\n");
}

void	ft_init_game_null(t_game *game)
{
	game->player_x = 0;
	game->player_y = 0;
	game->width = 0;
	game->height = 0;
	game->total_collectibles = 0;
	game->score = 0;
	game->moves = 0;
	game->mlx = NULL;
	game->win = NULL;
	game->map = NULL;
}

t_game	*ft_init_game(void)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
	{
		free(game);
		return (NULL);
	}
	game->map = malloc(sizeof(char *));
	game->wall = malloc(sizeof(void *));
	game->background = malloc(sizeof(void *));
	game->collectible = malloc(sizeof(void *));
	game->exit = malloc(sizeof(void *));
	game->player = malloc(sizeof(void *));
	if (!game->map || !game->wall || !game->background || !game->collectible || !game->exit || !game->player)
	{
		ft_free(game);
		return (NULL);
	}
	ft_init_game_null(game);
	return (game);
}

int	main(int argc, char **argv)
{
	//char	**map_path;
	t_game	*game;

	if (argc == 1)
		input_error("No map has been specified.\n");
	else if (argc > 2)
		input_error("Too many arguments.\n");
	else if (argc == 2 && check_map_arg(argv[1]))
	input_error("The specified map does not exist.\n");
	game = ft_init_game();
	if (!game)
		return (0);
	if (read_map(game, argv[1]) > 0)
		return (ft_free(game));
	//map_path = read_map(game, argv[1]);
	//if (!map_path)
	//	return (ft_free(game));
	call_map_validations(game->map, game);

	if (!game)
		return (0);
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		input_error("Failed to initialize mlx!\n");
	}
	game->win = mlx_new_window(game->mlx, game->width * TILE_SIZE, game->height * TILE_SIZE, "so_long");
	//game->map = map_path;
	load_map(game);
	draw_map(game);
	mlx_key_hook(game->win, move_player, game);
	mlx_hook(game->win, 17, 0, close_game, game);
	mlx_loop(game->mlx);
	return (0);
}
