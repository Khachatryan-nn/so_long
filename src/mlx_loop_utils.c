/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_loop_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tikhacha <tikhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:20:31 by tikhacha          #+#    #+#             */
/*   Updated: 2023/06/07 15:59:12 by tikhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	(*mlx).on_off = 0;
	mlx_clear_window(((*mlx)).ptr, ((*mlx)).win);
	free_matrix((*mlx).map, (*mlx).y);
	mlx_destroy_window((*mlx).ptr, (*mlx).win);
	free_vmatrix(mlx, (*mlx).gw.g, (*mlx).gw.gc);
	free_vmatrix(mlx, (*mlx).gw.w, (*mlx).gw.wc);
	free_vmatrix(mlx, (*mlx).p.pf, (*mlx).p.pfc);
	free_vmatrix(mlx, (*mlx).p.pl, (*mlx).p.plc);
	free_vmatrix(mlx, (*mlx).p.pr, (*mlx).p.prc);
	free_vmatrix(mlx, (*mlx).r.rv, (*mlx).r.rvc);
	free_vmatrix(mlx, (*mlx).d.d, (*mlx).d.dc);
	free_vmatrix(mlx, (*mlx).c.c, (*mlx).c.wc);
	exit (0);
}

int	keypressed(int keycode, t_mlx *mlx)
{
	if (keycode == KEYA || keycode == LEFTARROW)
		move_left(mlx);
	else if (keycode == KEYS || keycode == DOWNARROW)
		move_down(mlx);
	else if (keycode == KEYD || keycode == RIGHTARROW)
		move_right(mlx);
	else if (keycode == KEYW || keycode == UPARROW)
		move_up(mlx);
	else if (keycode == KEYESC)
		close_window(mlx);
	return (0);
}
