/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tikhacha <tikhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 18:18:10 by tikhacha          #+#    #+#             */
/*   Updated: 2023/05/13 21:39:04 by tikhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	static mlxloop(t_mlx *mlx)
{
	char	*i;

	if (MLX.on_off == 0)
		return (0);
	mlx_clear_window((MLX).ptr, (MLX).win);
	mlx_put_ground(mlx);
	mlx_put_sprites(mlx);
	i = ft_itoa(MLX.counter);
	mlx_string_put(MLX.ptr, MLX.win, 5, 0, BLUE, i);
	free(i);
	return (0);
}

void static	count_coins(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	MLX.c.n = 0;
	MLX.c.custom = 0;
	while (++i < MLX.y)
	{
		j = 0;
		while (++j < MLX.x)
		{
			if (MLX.map[i][j] == 'C')
				MLX.c.n++;
		}
	}
}

void static	mlx_hooks(t_mlx *mlx)
{
	mlx_clear_window((MLX).ptr, (MLX).win);
	mlx_hook(MLX.win, KeyDown, 1L<<0, keypressed, mlx);
	mlx_hook(MLX.win, REDCROSS, 1L<<0, close_window, mlx);
	mlx_loop_hook(MLX.ptr, mlxloop, mlx);
	mlx_do_sync(MLX.ptr);
	mlx_loop(MLX.ptr);
}

void	mlx_start(t_mlx *mlx)
{
	MLX.ptr = mlx_init();
	MLX.win = mlx_new_window(MLX.ptr, MLX.x * 48, MLX.y * 48, "so_long");
	MLX.w = 48;
	MLX.h = 48;
	MLX.c.coins = 0;
	MLX.on_off = 1;
	MLX.counter = 0;
	MLX.gw.gc = 8;
	MLX.gw.wc = 2;
	MLX.d.dc = 6;
	MLX.p.pfc = 4;
	MLX.p.prc = 8;
	MLX.r.rvc = 4;
	MLX.p.dir = 0;
	count_coins(mlx);
	load_sprites(mlx);
	load_sprites_2(mlx);
	load_sprites_3(mlx);
	mlx_hooks(mlx);
}
