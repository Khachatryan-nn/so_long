/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_rendering.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tikhacha <tikhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 17:20:22 by tikhacha          #+#    #+#             */
/*   Updated: 2023/05/14 15:23:11 by tikhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void static	mlx_put_player(t_mlx *mlx, int i, int j)
{
	static int k;

	if (MLX.p.dir == 0)
	{
		MPW(MLX.ptr, MLX.win, MLX.p.pf[frame(MLX.p.pfc)], j * S, i * S);
	}
	else if (MLX.p.dir == 2)
	{
		k++;
		MPW(MLX.ptr, MLX.win, MLX.p.pr[frame(MLX.p.pfc)], j * S, i * S);
	}
	else if (MLX.p.dir == 1)
	{
		k++;
		MPW(MLX.ptr, MLX.win, MLX.p.pl[frame(MLX.p.pfc)], j * S, i * S);
	}
	if (MLX.p.dir != 0 && k == MLX.p.plc + 5)
	{
		k = 0;
		MLX.p.dir = 0;
	}
}

void	mlx_put_ground(t_mlx *mlx)
{
	int	k;
	int	i;
	int	j;

	k = labs((long int) mlx) % labs((long int) MLX.map) % 10;
	i = 0;
	while (++i < MLX.y)
	{
		j = 0;
		while (++j < MLX.x)
		{
			if (k >= MLX.gw.gc)
				k = 0;
			if (MLX.map[i][j] != '1')
				MPW(MLX.ptr, MLX.win, MLX.gw.g[k++], j * S, i * S);
		}
	}
}

void	mlx_put_exit(t_mlx *mlx, int i, int j)
{
	if (MLX.c.coins == MLX.c.n && MLX.c.custom < MLX.d.dc)
	{
		MLX.c.custom++;
		MPW(MLX.ptr, MLX.win, MLX.d.d[frame(MLX.d.dc)], j * S, i * S);
	}
	else if (MLX.c.custom == 0)
		MPW(MLX.ptr, MLX.win, MLX.d.d[0], j * S, i * S);
	else
		MPW(MLX.ptr, MLX.win, MLX.d.d[MLX.d.dc - 1], j * S, i * S);
}

void	mlx_put_sprites(t_mlx *mlx)
{
	int			i;
	int			j;

	i = -1;
	while (++i < MLX.y)
	{
		j = -1;
		while (++j < MLX.x)
		{
			if (MLX.map[i][j] == 'P')
				mlx_put_player(mlx, i, j);
			else if (MLX.map[i][j] == 'R')
				MPW(MLX.ptr, MLX.win, MLX.r.rv[frame(MLX.r.rvc)], j * S, i * S);
			else if (MLX.map[i][j] == 'E')
				mlx_put_exit(mlx, i, j);
			else if (MLX.map[i][j] == '1' && i < MLX.y - 1 && \
				MLX.map[i + 1][j] == '1')
				MPW(MLX.ptr, MLX.win, MLX.gw.w[0], j * S, i * S);
			else if (MLX.map[i][j] == '1')
				MPW(MLX.ptr, MLX.win, MLX.gw.w[1], j * S, i * S);
			else if (MLX.map[i][j] == 'C')
				MPW(MLX.ptr, MLX.win, MLX.c.c[frame(MLX.c.wc)], j * S, i * S);
		}
	}
}
