/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tikhacha <tikhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 18:07:35 by tikhacha          #+#    #+#             */
/*   Updated: 2023/05/14 20:08:31 by tikhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_left(t_mlx *mlx)
{
	t_point	pos;

	ft_player_coord((*mlx).map, &pos);
	(*mlx).p.dir = 1;
	if ((*mlx).map[pos.y][pos.x - 1] != '1' && \
	(*mlx).map[pos.y][pos.x - 1] != 'E')
	{
		if ((*mlx).map[pos.y][pos.x - 1] == 'C')
			(*mlx).c.coins++;
		else if ((*mlx).map[pos.y][pos.x - 1] == 'R')
		{
			printf("\033[38;5;202mYou lose!\033[0m\n");
			close_window(mlx);
		}
		(*mlx).map[pos.y][pos.x - 1] = 'P';
		(*mlx).map[pos.y][pos.x] = '0';
		(*mlx).counter++;
	}
	else if ((*mlx).map[pos.y][pos.x - 1] == 'E' && \
	(*mlx).c.custom == (*mlx).d.dc)
		game_win(mlx, pos.y, pos.x, 'l');
}

void	move_right(t_mlx *mlx)
{
	t_point	pos;

	ft_player_coord((*mlx).map, &pos);
	(*mlx).p.dir = 2;
	if ((*mlx).map[pos.y][pos.x + 1] != '1' && \
	(*mlx).map[pos.y][pos.x + 1] != 'E')
	{
		if ((*mlx).map[pos.y][pos.x + 1] == 'C')
			(*mlx).c.coins++;
		else if ((*mlx).map[pos.y][pos.x + 1] == 'R')
		{
			printf("\033[38;5;202mYou lose!\033[0m\n");
			close_window(mlx);
		}
		(*mlx).map[pos.y][pos.x + 1] = 'P';
		(*mlx).map[pos.y][pos.x] = '0';
		(*mlx).counter++;
	}
	else if ((*mlx).map[pos.y][pos.x + 1] == 'E' && \
	(*mlx).c.custom == (*mlx).d.dc)
		game_win(mlx, pos.y, pos.x, 'r');
}

void	move_up(t_mlx *mlx)
{
	t_point	pos;

	ft_player_coord((*mlx).map, &pos);
	(*mlx).p.dir = 0;
	if ((*mlx).map[pos.y - 1][pos.x] != '1' && \
	(*mlx).map[pos.y - 1][pos.x] != 'E')
	{
		if ((*mlx).map[pos.y - 1][pos.x] == 'C')
			(*mlx).c.coins++;
		else if ((*mlx).map[pos.y - 1][pos.x] == 'R')
		{
			printf("\033[38;5;202mYou lose!\033[0m\n");
			close_window(mlx);
		}
		(*mlx).map[pos.y - 1][pos.x] = 'P';
		(*mlx).map[pos.y][pos.x] = '0';
		(*mlx).counter++;
	}
	else if ((*mlx).map[pos.y - 1][pos.x] == 'E' && \
	(*mlx).c.custom == (*mlx).d.dc)
		game_win(mlx, pos.y, pos.x, 'u');
}

void	move_down(t_mlx *mlx)
{
	t_point	pos;

	ft_player_coord((*mlx).map, &pos);
	(*mlx).p.dir = 0;
	if ((*mlx).map[pos.y + 1][pos.x] != '1' && \
	(*mlx).map[pos.y + 1][pos.x] != 'E')
	{
		if ((*mlx).map[pos.y + 1][pos.x] == 'C')
			(*mlx).c.coins++;
		else if ((*mlx).map[pos.y + 1][pos.x] == 'R')
		{
			printf("\033[38;5;202mYou lose!\033[0m\n");
			close_window(mlx);
		}
		(*mlx).map[pos.y + 1][pos.x] = 'P';
		(*mlx).map[pos.y][pos.x] = '0';
		(*mlx).counter++;
	}
	else if ((*mlx).map[pos.y + 1][pos.x] == 'E' && \
	(*mlx).c.custom == (*mlx).d.dc)
		game_win(mlx, pos.y, pos.x, 'd');
}
