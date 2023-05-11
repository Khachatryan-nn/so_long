/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tikhacha <tikhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 18:18:10 by tikhacha          #+#    #+#             */
/*   Updated: 2023/05/11 19:43:42 by tikhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	static mlxloop(t_mlx *mlx)
{
	if (MLX.on_off == 0)
		return (0);
	mlx_clear_window((MLX).ptr, (MLX).win);
	mlx_put_ground(mlx);
	mlx_put_sprites(mlx);
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

void	mlx_start(t_mlx *mlx)
{
	MLX.ptr = mlx_init();
	MLX.win = mlx_new_window(MLX.ptr, MLX.x * 48, MLX.y * 48, "so_long");
	MLX.w = 48;
	MLX.h = 48;
	MLX.c.coins = 0;
	MLX.on_off = 1;
	MLX.counter = 0;
	count_coins(mlx);
	load_sprites(mlx);
	load_sprites_2(mlx);
	load_sprites_3(mlx);
	mlx_hook(MLX.win, KeyDown, 0, &keypressed, mlx);
	mlx_hook(MLX.win, REDCROSS, 0, &close_window, mlx);
	mlx_loop_hook(MLX.ptr, &mlxloop, mlx);
	mlx_loop(MLX.ptr);
}
