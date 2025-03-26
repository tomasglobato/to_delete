/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togomes- <togomes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 21:29:59 by togomes-          #+#    #+#             */
/*   Updated: 2025/03/25 19:21:39 by togomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	initialize_player_position(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (game->map[y] != NULL)
	{
		x = 0;
		while (game->map[y][x] != '\0')
		{
			if (game->map[y][x] == 'P')
			{
				game->player_x = x;
				game->player_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

int	is_valid_move(t_game *game, int new_x, int new_y)
{
	if (new_x <= 0 || new_y <= 0 || new_x >= game->width|| new_y >= game->height)
		return (0);
	if (game->map[new_y][new_x] == '1')
		return (0);
	if (game->map[new_y][new_x] == 'E' && game->total_collectibles > 0)
		return (0);
	return (1);
}

int	move_player(int keycode, t_game *game)
{
	int	prev_x;
	int	prev_y;

	if (!game->map || !game)
		return (0);
	prev_x = game->player_x;
	prev_y = game->player_y;
	if (keycode == KEY_ESC || keycode == 17)
	{
		mlx_destroy_window(game->mlx, game->win);
		exit(0);
	}
	if (keycode == KEY_W || keycode == KEY_UP)
	{
		if (is_valid_move(game, game->player_x, game->player_y - 1))
		{
			game->player_y--;
			game->moves++;
			ft_printf("Moves: %d\n", game->moves);
		}
	}
	else if (keycode == KEY_S || keycode == KEY_DOWN)
	{
		if (is_valid_move(game, game->player_x, game->player_y + 1))
		{
			game->player_y++;
			game->moves++;
			ft_printf("Moves: %d\n", game->moves);
		}
	}
	else if (keycode == KEY_A || keycode == KEY_LEFT)
	{
		if (is_valid_move(game, game->player_x - 1, game->player_y))
		{
			game->player_x--;
			game->moves++;
			ft_printf("Moves: %d\n", game->moves);
		}
	}
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
	{
		if (is_valid_move(game, game->player_x + 1, game->player_y))
		{
			game->player_x++;
			game->moves++;
			ft_printf("Moves: %d\n", game->moves);
		}
	}
	if (game->map[game->player_y][game->player_x] == 'C')
	{
		game->map[game->player_y][game->player_x] = '0';//remove o coletavel
		game->score++;
		game->total_collectibles--;
		ft_printf("Score: %d\n", game->score);
	}
	if (game->map[game->player_y][game->player_x] == 'E')
	{
		ft_printf("You won!\nScore: %d\n", game->score);
		if (game->total_collectibles == 0) //validacao para ver se foram todos recolhidos
		{
			mlx_destroy_window(game->mlx, game->win);//Fecha a janela
			exit(0);//Termina o jogo
		}
		printf("You need to collect all collectibles first!\n");//nunca entra aqui porque para acima.
	}
	if (game->map[prev_y][prev_x] != 'E' && game->map[game->player_y][game->player_x] != 'E')
		game->map[prev_y][prev_x] = '0';//Remove a posicao anterior do jogador
	if (game->map[game->player_y][game->player_x] != 'E')
		game->map[game->player_y][game->player_x] = 'P';//Atualiza a posicao do jogador
	else if (game->map[game->player_y][game->player_x] == 'E' && game->total_collectibles == 0)
		game->map[game->player_y][game->player_x] = 'E';//Atualiza a posicao do jogador
	mlx_clear_window(game->mlx, game->win);//Limpa a janela do jogo
	draw_map(game);//Desenha novamente o mapa apos o movimento
	return (0);
}
