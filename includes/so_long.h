/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togomes- <togomes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 13:03:23 by togomes-          #+#    #+#             */
/*   Updated: 2025/03/26 21:27:12 by togomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define TILE_SIZE 64
# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define WALL '1'
# define PLAYER 'P'
# define COLLECTIBLE 'C'
# define EXIT 'E'
# define BACKGROUND '0'
# include "../mlx/mlx.h"
# include "../get_next_line/get_next_line.h"
# include "../ft_printf/ft_printf.h"
# include "../ft_printf/libft/libft.h"
# include "structures.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

int     main(int argc, char **argv);

int     map_validation(char **map, t_game *game);
int     is_valid_move(t_game *game, int x, int y);

void     count_lines_and_columns(char **map, t_game *s_map_structure);

int	check_map_arg(char *map_path);

void	map_error(char *s, ...);
void	input_error(char *s, ...);

void    call_map_validations(char **map_path, t_game *game);

int		read_map(t_game *game, char *filename);

char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *str);

int	 path(t_game *game);

void	draw_map(t_game *game);


void	initialize_player_position(t_game *game);
int	move_player(int keycode, t_game *game);

int    ft_free(t_game *game);


#endif
