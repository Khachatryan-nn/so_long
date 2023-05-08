/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tikhacha <tikhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 18:18:10 by tikhacha          #+#    #+#             */
/*   Updated: 2023/05/08 19:24:11 by tikhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void static	mlx_put_player(t_mlx *mlx)
{
	int	i;
	int	j;
	int	h;
	int	w;

	i = 0;
	w = 48;
	h = 48;
	while (++i < (*mlx).y)
	{
		j = 0;
		while (++j < (*mlx).x)
		{
			if ((*mlx).map[i][j] == 'P')
				mlx_put_image_to_window((*mlx).ptr, (*mlx).win, (*mlx).player.pf0, j * w, i * h);
			else if ((*mlx).map[i][j] == 'R')
				mlx_put_image_to_window((*mlx).ptr, (*mlx).win, (*mlx).rival.rv0, j * w, i * h);
		}
	}
}

void static	load_sprites(t_mlx *mlx)
{
	(*mlx).player.pf0 = mlx_xpm_file_to_image((*mlx).ptr, "./sprites/P_1.xpm", &(*mlx).w, &(*mlx).h);
	(*mlx).player.pf1 = mlx_xpm_file_to_image((*mlx).ptr, "./sprites/P_2.xpm", &(*mlx).w, &(*mlx).h);
	(*mlx).player.pf2 = mlx_xpm_file_to_image((*mlx).ptr, "./sprites/P_3.xpm", &(*mlx).w, &(*mlx).h);
	(*mlx).player.pf3 = mlx_xpm_file_to_image((*mlx).ptr, "./sprites/P_4.xpm", &(*mlx).w, &(*mlx).h);
	(*mlx).player.pr0 = mlx_xpm_file_to_image((*mlx).ptr, "./sprites/Pr_0.xpm", &(*mlx).w, &(*mlx).h);
	(*mlx).player.pr1 = mlx_xpm_file_to_image((*mlx).ptr, "./sprites/Pr_1.xpm", &(*mlx).w, &(*mlx).h);
	(*mlx).player.pr2 = mlx_xpm_file_to_image((*mlx).ptr, "./sprites/Pr_2.xpm", &(*mlx).w, &(*mlx).h);
	(*mlx).player.pr3 = mlx_xpm_file_to_image((*mlx).ptr, "./sprites/Pr_3.xpm", &(*mlx).w, &(*mlx).h);
	(*mlx).player.pr4 = mlx_xpm_file_to_image((*mlx).ptr, "./sprites/Pr_4.xpm", &(*mlx).w, &(*mlx).h);
	(*mlx).player.pr5 = mlx_xpm_file_to_image((*mlx).ptr, "./sprites/Pr_5.xpm", &(*mlx).w, &(*mlx).h);
	(*mlx).player.pr6 = mlx_xpm_file_to_image((*mlx).ptr, "./sprites/Pr_6.xpm", &(*mlx).w, &(*mlx).h);
	(*mlx).player.pr7 = mlx_xpm_file_to_image((*mlx).ptr, "./sprites/Pr_7.xpm", &(*mlx).w, &(*mlx).h);
	(*mlx).rival.rv0 = mlx_xpm_file_to_image((*mlx).ptr, "./sprites/Rv_0.xpm", &(*mlx).w, &(*mlx).h);
	(*mlx).rival.rv1 = mlx_xpm_file_to_image((*mlx).ptr, "./sprites/Rv_1.xpm", &(*mlx).w, &(*mlx).h);
	(*mlx).rival.rv2 = mlx_xpm_file_to_image((*mlx).ptr, "./sprites/Rv_2.xpm", &(*mlx).w, &(*mlx).h);
	(*mlx).rival.rv3 = mlx_xpm_file_to_image((*mlx).ptr, "./sprites/Rv_3.xpm", &(*mlx).w, &(*mlx).h);
	// (*mlx).gAndW.g0 = mlx_
}

void	mlx_start(t_mlx *mlx)
{
	(*mlx).ptr = mlx_init();
	(*mlx).win = mlx_new_window((*mlx).ptr, (*mlx).x * 48, (*mlx).y * 48, "so_long");
	(*mlx).w = 48;
	(*mlx).h = 48;
	load_sprites(mlx);
	load_sprites_2(mlx);
	mlx_put_player(mlx);
	// mlx_put_coin(mlx);
	//(*mlx).img.ptr = mlx_xpm_file_to_image((*mlx).ptr, "./sprites/P_2.xpm", &width, &height);
	//mlx_put_image_to_window((*mlx).ptr, (*mlx).win, (*mlx).img.ptr, 50, 50);
	//(*mlx).img.ptr = mlx_xpm_file_to_image((*mlx).ptr, "./sprites/P_3.xpm", &width, &height);
	//mlx_put_image_to_window((*mlx).ptr, (*mlx).win, (*mlx).img.ptr, 100, 100);
	//(*mlx).img.ptr = mlx_xpm_file_to_image((*mlx).ptr, "./sprites/P_4.xpm", &width, &height);
	//mlx_put_image_to_window((*mlx).ptr, (*mlx).win, (*mlx).img.ptr, 50, 0);
	//(*mlx).img.ptr = mlx_xpm_file_to_image((*mlx).ptr, "./sprites/Ground.xpm", &width, &height);
	//mlx_put_image_to_window((*mlx).ptr, (*mlx).win, (*mlx).img.ptr, 0, 50);
	mlx_loop((*mlx).ptr);
}

//mlx_hook_loop

//2 -> klaviaturayic nermucum
//27 -> x-ov pagel
