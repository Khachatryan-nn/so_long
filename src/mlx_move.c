/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tikhacha <tikhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 18:07:35 by tikhacha          #+#    #+#             */
/*   Updated: 2023/05/12 17:42:04 by tikhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_left(t_mlx *mlx)
{
	t_point pos;

	ft_player_coord(MLX.map, &pos);
	MLX.p.dir = 1;
	if (MLX.map[pos.y][pos.x - 1] != '1' && MLX.map[pos.y][pos.x - 1] != 'E')
	{
		if (MLX.map[pos.y][pos.x - 1] == 'C')
			MLX.c.coins++;
		else if (MLX.map[pos.y][pos.x - 1] == 'R')
		{
			printf("\033[38;5;202mYou lose!\033[0m\n");
			close_window(mlx);
		}
		MLX.map[pos.y][pos.x - 1] = 'P';
		MLX.map[pos.y][pos.x] = '0';
		MLX.counter++;
	}
	else if (MLX.map[pos.y][pos.x - 1] == 'E' && MLX.c.custom == MLX.d.dc)
		game_win(mlx, pos.y, pos.x, 'l');
}

void	move_right(t_mlx *mlx)
{
	t_point pos;

	ft_player_coord(MLX.map, &pos);
	MLX.p.dir = 2;
	if (MLX.map[pos.y][pos.x + 1] != '1' && MLX.map[pos.y][pos.x + 1] != 'E')
	{
		if (MLX.map[pos.y][pos.x + 1] == 'C')
			MLX.c.coins++;
		else if (MLX.map[pos.y][pos.x + 1] == 'R')
		{
			printf("\033[38;5;202mYou lose!\033[0m\n");
			close_window(mlx);
		}
		MLX.map[pos.y][pos.x + 1] = 'P';
		MLX.map[pos.y][pos.x] = '0';
		MLX.counter++;
	}
	else if (MLX.map[pos.y][pos.x + 1] == 'E' && MLX.c.custom == MLX.d.dc)
		game_win(mlx, pos.y, pos.x, 'r');
}

void	move_up(t_mlx *mlx)
{
	t_point pos;

	ft_player_coord(MLX.map, &pos);
	MLX.p.dir = 0;
	if (MLX.map[pos.y - 1][pos.x] != '1' && MLX.map[pos.y - 1][pos.x] != 'E')
	{
		if (MLX.map[pos.y - 1][pos.x] == 'C')
			MLX.c.coins++;
		else if (MLX.map[pos.y - 1][pos.x] == 'R')
		{
			printf("\033[38;5;202mYou lose!\033[0m\n");
			close_window(mlx);
		}
		MLX.map[pos.y - 1][pos.x] = 'P';
		MLX.map[pos.y][pos.x] = '0';
		MLX.counter++;
	}
	else if (MLX.map[pos.y - 1][pos.x] == 'E' && MLX.c.custom == MLX.d.dc)
		game_win(mlx, pos.y, pos.x, 'u');
}

void	move_down(t_mlx *mlx)
{
	t_point pos;

	ft_player_coord(MLX.map, &pos);
	MLX.p.dir = 0;
	if (MLX.map[pos.y + 1][pos.x] != '1' && MLX.map[pos.y + 1][pos.x] != 'E')
	{
		if (MLX.map[pos.y + 1][pos.x] == 'C')
			MLX.c.coins++;
		else if (MLX.map[pos.y + 1][pos.x] == 'R')
		{
			printf("\033[38;5;202mYou lose!\033[0m\n");
			close_window(mlx);
		}
		MLX.map[pos.y + 1][pos.x] = 'P';
		MLX.map[pos.y][pos.x] = '0';
		MLX.counter++;
	}
	else if (MLX.map[pos.y + 1][pos.x] == 'E' && MLX.c.custom == MLX.d.dc)
		game_win(mlx, pos.y, pos.x, 'd');
}
