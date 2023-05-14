/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_rendering.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tikhacha <tikhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 17:20:22 by tikhacha          #+#    #+#             */
/*   Updated: 2023/05/14 20:07:15 by tikhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void static	mlx_put_player(t_mlx *mlx, int i, int j)
{
	static int	k;

	if ((*mlx).p.dir == 0)
	{
		mlx_put_image_to_window((*mlx).ptr, (*mlx).win, \
		(*mlx).p.pf[frame((*mlx).p.pfc)], j * S, i * S);
	}
	else if ((*mlx).p.dir == 2)
	{
		k++;
		mlx_put_image_to_window((*mlx).ptr, (*mlx).win, \
		(*mlx).p.pr[frame((*mlx).p.pfc)], j * S, i * S);
	}
	else if ((*mlx).p.dir == 1)
	{
		k++;
		mlx_put_image_to_window((*mlx).ptr, (*mlx).win, \
		(*mlx).p.pl[frame((*mlx).p.pfc)], j * S, i * S);
	}
	if ((*mlx).p.dir != 0 && k == (*mlx).p.plc + 5)
	{
		k = 0;
		(*mlx).p.dir = 0;
	}
}

void	mlx_put_ground(t_mlx *mlx)
{
	int	k;
	int	i;
	int	j;

	k = labs((long int)mlx) % labs((long int)(*mlx).map) % 10;
	i = 0;
	while (++i < (*mlx).y)
	{
		j = 0;
		while (++j < (*mlx).x)
		{
			if (k >= (*mlx).gw.gc)
				k = 0;
			if ((*mlx).map[i][j] != '1')
				mlx_put_image_to_window((*mlx).ptr, \
				(*mlx).win, (*mlx).gw.g[k++], j * S, i * S);
		}
	}
}

void	mlx_put_exit(t_mlx *mlx, int i, int j)
{
	if ((*mlx).c.coins == (*mlx).c.n && (*mlx).c.custom < (*mlx).d.dc)
	{
		(*mlx).c.custom++;
		mlx_put_image_to_window((*mlx).ptr, (*mlx).win, \
		(*mlx).d.d[frame((*mlx).d.dc)], j * S, i * S);
	}
	else if ((*mlx).c.custom == 0)
		mlx_put_image_to_window((*mlx).ptr, (*mlx).win, \
		(*mlx).d.d[0], j * S, i * S);
	else
		mlx_put_image_to_window((*mlx).ptr, (*mlx).win, \
		(*mlx).d.d[(*mlx).d.dc - 1], j * S, i * S);
}

void	mlx_put_sprites(t_mlx *mlx)
{
	int			i;
	int			j;

	i = -1;
	while (++i < (*mlx).y)
	{
		j = -1;
		while (++j < (*mlx).x)
		{
			if ((*mlx).map[i][j] == 'P')
				mlx_put_player(mlx, i, j);
			else if ((*mlx).map[i][j] == 'R')
				mlx_put_image_to_window((*mlx).ptr, \
				(*mlx).win, (*mlx).r.rv[frame((*mlx).r.rvc)], j * S, i * S);
			else if ((*mlx).map[i][j] == 'E')
				mlx_put_exit(mlx, i, j);
			else if ((*mlx).map[i][j] == '1' && i < \
			(*mlx).y - 1 && \
				(*mlx).map[i + 1][j] == '1')
				mlx_put_image_to_window((*mlx).ptr, \
				(*mlx).win, (*mlx).gw.w[0], j * S, i * S);
			else if ((*mlx).map[i][j] == '1')
				mlx_put_image_to_window((*mlx).ptr, \
				(*mlx).win, (*mlx).gw.w[1], j * S, i * S);
			else if ((*mlx).map[i][j] == 'C')
				mlx_put_image_to_window((*mlx).ptr, \
				(*mlx).win, (*mlx).c.c[frame((*mlx).c.wc)], j * S, i * S);
		}
	}
}
