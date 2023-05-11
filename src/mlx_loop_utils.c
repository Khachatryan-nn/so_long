/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_loop_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tikhacha <tikhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:20:31 by tikhacha          #+#    #+#             */
/*   Updated: 2023/05/11 14:01:38 by tikhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	close_window(t_mlx *mlx)
{
	mlx_loop_end(MLX.ptr);
	MLX.on_off = 0;
	if (MLX.map)
		free_matrix(MLX.map, MLX.y);
	if (MLX.win)
		mlx_destroy_window(MLX.ptr, MLX.win);
	if (MLX.gw.g)
		free_vmatrix(mlx, MLX.gw.g, MLX.gw.gc);
	if (MLX.gw.w)
		free_vmatrix(mlx, MLX.gw.w, MLX.gw.wc);
	if (MLX.p.pf)
		free_vmatrix(mlx, MLX.p.pf, MLX.p.pfc);
	if (MLX.p.pr)
		free_vmatrix(mlx, MLX.p.pr, MLX.p.prc);
	if (MLX.r.rv)
		free_vmatrix(mlx, MLX.r.rv, MLX.r.rvc);
	if (MLX.c.c)
		free_vmatrix(mlx, MLX.c.c, MLX.c.wc);
	if (MLX.d.d)
		free_vmatrix(mlx, MLX.d.d, MLX.d.dc);
	return (0);
}

int	keypressed(int keycode, void *mlx)
{
	(void) mlx;
	if (keycode == 97)
	{
		printf("A worked\n");
		//if (MLX.map[i][j])
	}
	else if (keycode == 115)
		printf("S worked\n");
	return (0);
}
