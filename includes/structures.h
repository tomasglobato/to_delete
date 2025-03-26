/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togomes- <togomes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 15:03:23 by togomes-          #+#    #+#             */
/*   Updated: 2025/03/24 22:54:05 by togomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

# include "so_long.h"

typedef struct s_game {
    void *mlx;
    void *win;
    char **map;
    int width;
    int height;
    int lines;
    int player_x;
    int player_y;
    int moves;
    int score;
    int total_collectibles;
    void *wall;
    void *background;
    void *collectible;
    void *exit;
    void *player;
} t_game;

#endif
