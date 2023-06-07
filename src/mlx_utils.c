/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tikhacha <tikhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 18:18:10 by tikhacha          #+#    #+#             */
/*   Updated: 2023/06/07 15:59:12 by tikhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	static	mlxloop(t_mlx *mlx)
{
	char	*i;

	if ((*mlx).on_off == 0)
		return (0);
	mlx_clear_window(((*mlx)).ptr, ((*mlx)).win);
	mlx_put_ground(mlx);
	mlx_put_sprites(mlx);
	i = ft_itoa((*mlx).counter);
	mlx_string_put((*mlx).ptr, (*mlx).win, 5, 0, BLUE, i);
	free(i);
	return (0);
}

void static	count_coins(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	(*mlx).c.n = 0;
	(*mlx).c.custom = 0;
	while (++i < (*mlx).y)
	{
		j = 0;
		while (++j < (*mlx).x)
		{
			if ((*mlx).map[i][j] == 'C')
				(*mlx).c.n++;
		}
	}
}

void static	mlx_hooks(t_mlx *mlx)
{
	mlx_clear_window(((*mlx)).ptr, ((*mlx)).win);
	mlx_hook((*mlx).win, KEYDOWN, 1L << 0, keypressed, mlx);
	mlx_hook((*mlx).win, REDCROSS, 1L << 0, close_window, mlx);
	mlx_loop_hook((*mlx).ptr, mlxloop, mlx);
	mlx_do_sync((*mlx).ptr);
	mlx_loop((*mlx).ptr);
}

void	mlx_start(t_mlx *mlx)
{
	(*mlx).ptr = mlx_init();
	(*mlx).win = mlx_new_window((*mlx).ptr, (*mlx).x * 48, \
		(*mlx).y * 48, "./so_long");
	(*mlx).w = 48;
	(*mlx).h = 48;
	(*mlx).c.coins = 0;
	(*mlx).on_off = 1;
	(*mlx).counter = 0;
	(*mlx).gw.gc = 8;
	(*mlx).gw.wc = 2;
	(*mlx).d.dc = 6;
	(*mlx).p.pfc = 4;
	(*mlx).p.prc = 8;
	(*mlx).r.rvc = 4;
	(*mlx).p.dir = 0;
	(*mlx).c.wc = 3;
	(*mlx).p.plc = 8;
	(*mlx).p.pf = (void **)malloc(sizeof(void *) * (*mlx).p.pfc);
	(*mlx).p.pr = (void **)malloc(sizeof(void *) * (*mlx).p.prc);
	(*mlx).r.rv = (void **)malloc(sizeof(void *) * (*mlx).r.rvc);
	count_coins(mlx);
	load_sprites(mlx);
	load_sprites_2(mlx);
	load_sprites_3(mlx);
	mlx_hooks(mlx);
}
