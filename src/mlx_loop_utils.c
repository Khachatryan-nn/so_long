/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_loop_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tikhacha <tikhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:20:31 by tikhacha          #+#    #+#             */
/*   Updated: 2023/05/14 18:45:10 by tikhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	frame(int n)
{
	static int	k;

	k++;
	if (k == 10000)
		k = 0;
	return ((k / 150) % n);
}

int	close_window(t_mlx *mlx)
{
	MLX.on_off = 0;
	mlx_clear_window((MLX).ptr, (MLX).win);
	free_matrix(MLX.map, MLX.y);
	mlx_destroy_window(MLX.ptr, MLX.win);
	free_vmatrix(mlx, MLX.gw.g, MLX.gw.gc);
	free_vmatrix(mlx, MLX.gw.w, MLX.gw.wc);
	free_vmatrix(mlx, MLX.p.pf, MLX.p.pfc);
	free_vmatrix(mlx, MLX.p.pl, MLX.p.plc);
	free_vmatrix(mlx, MLX.p.pr, MLX.p.prc);
	free_vmatrix(mlx, MLX.r.rv, MLX.r.rvc);
	free_vmatrix(mlx, MLX.d.d, MLX.d.dc);
	free_vmatrix(mlx, MLX.c.c, MLX.c.wc);
	exit (0);
}

int	keypressed(int keycode, t_mlx *mlx)
{
	if (keycode == keyA || keycode == LeftArrow)
		move_left(mlx);
	else if (keycode == keyS || keycode == DownArrow)
		move_down(mlx);
	else if (keycode == keyD || keycode == RightArrow)
		move_right(mlx);
	else if (keycode == keyW || keycode == UpArrow)
		move_up(mlx);
	else if (keycode == keyEsc || keycode == keyC)
		close_window(mlx);
	return (0);
}
