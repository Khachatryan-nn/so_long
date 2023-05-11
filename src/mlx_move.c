/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tikhacha <tikhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 18:07:35 by tikhacha          #+#    #+#             */
/*   Updated: 2023/05/11 19:46:31 by tikhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_left(t_mlx *mlx)
{
	t_point pos;
	int		temp;

	ft_player_coord(MLX.map, &pos);
	temp = pos.x;
	pos.x = pos.y;
	pos.y = temp;
	if (MLX.map[pos.x][pos.y - 1] != '1' && MLX.map[pos.x][pos.y - 1] != 'E')
	{
		if (MLX.map[pos.x][pos.y - 1] == 'C')
			MLX.c.coins++;
		else if (MLX.map[pos.x][pos.y - 1] == 'R')
		{
			write(1, "You lose\n", 9);
			close_window(mlx);
		}
		MLX.map[pos.x][pos.y - 1] = 'P';
		MLX.map[pos.x][pos.y] = '0';
		MLX.counter++;
	}
	else if (MLX.map[pos.x][pos.y - 1] == 'E' && MLX.c.custom == MLX.d.dc)
		game_win(mlx, pos.x, pos.y, 'l');
}

void	move_right(t_mlx *mlx)
{
	t_point pos;
	int		temp;

	ft_player_coord(MLX.map, &pos);
	temp = pos.x;
	pos.x = pos.y;
	pos.y = temp;
	if (MLX.map[pos.x][pos.y + 1] != '1' && MLX.map[pos.x][pos.y + 1] != 'E')
	{
		if (MLX.map[pos.x][pos.y + 1] == 'C')
			MLX.c.coins++;
		else if (MLX.map[pos.x][pos.y + 1] == 'R')
		{
			write(1, "You lose\n", 9);
			close_window(mlx);
		}
		MLX.map[pos.x][pos.y + 1] = 'P';
		MLX.map[pos.x][pos.y] = '0';
		MLX.counter++;
	}
	else if (MLX.map[pos.x][pos.y + 1] == 'E' && MLX.c.custom == MLX.d.dc)
		game_win(mlx, pos.x, pos.y, 'r');
}

void	move_up(t_mlx *mlx)
{
	t_point pos;
	int		temp;

	ft_player_coord(MLX.map, &pos);
	temp = pos.x;
	pos.x = pos.y;
	pos.y = temp;
	if (MLX.map[pos.x - 1][pos.y] != '1' && MLX.map[pos.x - 1][pos.y] != 'E')
	{
		if (MLX.map[pos.x - 1][pos.y] == 'C')
			MLX.c.coins++;
		else if (MLX.map[pos.x - 1][pos.y] == 'R')
		{
			write(1, "You lose\n", 9);
			close_window(mlx);
		}
		MLX.map[pos.x - 1][pos.y] = 'P';
		MLX.map[pos.x][pos.y] = '0';
		MLX.counter++;
	}
	else if (MLX.map[pos.x - 1][pos.y] == 'E' && MLX.c.custom == MLX.d.dc)
		game_win(mlx, pos.x, pos.y, 'u');
}

void	move_down(t_mlx *mlx)
{
	t_point pos;
	int		temp;

	ft_player_coord(MLX.map, &pos);
	temp = pos.x;
	pos.x = pos.y;
	pos.y = temp;
	if (MLX.map[pos.x + 1][pos.y] != '1' && MLX.map[pos.x + 1][pos.y] != 'E')
	{
		if (MLX.map[pos.x + 1][pos.y] == 'C')
			MLX.c.coins++;
		else if (MLX.map[pos.x + 1][pos.y] == 'R')
		{
			write(1, "You lose\n", 9);
			close_window(mlx);
		}
		MLX.map[pos.x + 1][pos.y] = 'P';
		MLX.map[pos.x][pos.y] = '0';
		MLX.counter++;
	}
	else if (MLX.map[pos.x + 1][pos.y] == 'E' && MLX.c.custom == MLX.d.dc)
		game_win(mlx, pos.x, pos.y, 'd');
}
