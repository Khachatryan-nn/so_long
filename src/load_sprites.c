/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tikhacha <tikhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 19:15:05 by tikhacha          #+#    #+#             */
/*   Updated: 2023/05/16 12:06:15 by tikhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void static	load_sprites_helper(t_mlx *mlx)
{
	(*mlx).p.pr[7] = mlx_xpm_file_to_image((*mlx).ptr, \
		"./spr/Pr_7.xpm", &(*mlx).w, &(*mlx).h);
	(*mlx).r.rv[0] = mlx_xpm_file_to_image((*mlx).ptr, \
		"./spr/Rv_0.xpm", &(*mlx).w, &(*mlx).h);
	(*mlx).r.rv[1] = mlx_xpm_file_to_image((*mlx).ptr, \
		"./spr/Rv_1.xpm", &(*mlx).w, &(*mlx).h);
	(*mlx).r.rv[2] = mlx_xpm_file_to_image((*mlx).ptr, \
		"./spr/Rv_2.xpm", &(*mlx).w, &(*mlx).h);
	(*mlx).r.rv[3] = mlx_xpm_file_to_image((*mlx).ptr, \
		"./spr/Rv_3.xpm", &(*mlx).w, &(*mlx).h);
	(*mlx).d.d[0] = mlx_xpm_file_to_image((*mlx).ptr, \
		"./spr/D_0.xpm", &(*mlx).w, &(*mlx).h);
	(*mlx).d.d[1] = mlx_xpm_file_to_image((*mlx).ptr, \
		"./spr/D_1.xpm", &(*mlx).w, &(*mlx).h);
	(*mlx).d.d[2] = mlx_xpm_file_to_image((*mlx).ptr, \
		"./spr/D_2.xpm", &(*mlx).w, &(*mlx).h);
	(*mlx).d.d[3] = mlx_xpm_file_to_image((*mlx).ptr, \
		"./spr/D_3.xpm", &(*mlx).w, &(*mlx).h);
	(*mlx).d.d[4] = mlx_xpm_file_to_image((*mlx).ptr, \
		"./spr/D_4.xpm", &(*mlx).w, &(*mlx).h);
	(*mlx).d.d[5] = mlx_xpm_file_to_image((*mlx).ptr, \
		"./spr/D_5.xpm", &(*mlx).w, &(*mlx).h);
	(*mlx).p.pl[7] = mlx_xpm_file_to_image((*mlx).ptr, \
		"./spr/Pl_7.xpm", &(*mlx).w, &(*mlx).h);
}

void	load_sprites(t_mlx *mlx)
{
	(*mlx).p.pf[0] = mlx_xpm_file_to_image((*mlx).ptr, \
		"./spr/P_1.xpm", &(*mlx).w, &(*mlx).h);
	(*mlx).p.pf[1] = mlx_xpm_file_to_image((*mlx).ptr, \
		"./spr/P_2.xpm", &(*mlx).w, &(*mlx).h);
	(*mlx).p.pf[2] = mlx_xpm_file_to_image((*mlx).ptr, \
		"./spr/P_3.xpm", &(*mlx).w, &(*mlx).h);
	(*mlx).p.pf[3] = mlx_xpm_file_to_image((*mlx).ptr, \
		"./spr/P_4.xpm", &(*mlx).w, &(*mlx).h);
	(*mlx).p.pr[0] = mlx_xpm_file_to_image((*mlx).ptr, \
		"./spr/Pr_0.xpm", &(*mlx).w, &(*mlx).h);
	(*mlx).p.pr[1] = mlx_xpm_file_to_image((*mlx).ptr, \
		"./spr/Pr_1.xpm", &(*mlx).w, &(*mlx).h);
	(*mlx).p.pr[2] = mlx_xpm_file_to_image((*mlx).ptr, \
		"./spr/Pr_2.xpm", &(*mlx).w, &(*mlx).h);
	(*mlx).p.pr[3] = mlx_xpm_file_to_image((*mlx).ptr, \
		"./spr/Pr_3.xpm", &(*mlx).w, &(*mlx).h);
	(*mlx).p.pr[4] = mlx_xpm_file_to_image((*mlx).ptr, \
		"./spr/Pr_4.xpm", &(*mlx).w, &(*mlx).h);
	(*mlx).p.pr[5] = mlx_xpm_file_to_image((*mlx).ptr, \
		"./spr/Pr_5.xpm", &(*mlx).w, &(*mlx).h);
	(*mlx).p.pr[6] = mlx_xpm_file_to_image((*mlx).ptr, \
		"./spr/Pr_6.xpm", &(*mlx).w, &(*mlx).h);
}

void	load_sprites_2(t_mlx *mlx)
{
	(*mlx).gw.g = (void **)malloc(sizeof(void *) * (*mlx).gw.gc);
	(*mlx).gw.w = (void **)malloc(sizeof(void *) * (*mlx).gw.wc);
	(*mlx).d.d = (void **)malloc(sizeof(void *) * (*mlx).d.dc);
	(*mlx).gw.w[0] = mlx_xpm_file_to_image((*mlx).ptr, \
		"./spr/w_0.xpm", &(*mlx).w, &(*mlx).h);
	(*mlx).gw.w[1] = mlx_xpm_file_to_image((*mlx).ptr, \
		"./spr/w_1.xpm", &(*mlx).w, &(*mlx).h);
	(*mlx).gw.g[0] = mlx_xpm_file_to_image((*mlx).ptr, \
		"./spr/gr_0.xpm", &(*mlx).w, &(*mlx).h);
	(*mlx).gw.g[1] = mlx_xpm_file_to_image((*mlx).ptr, \
		"./spr/gr_1.xpm", &(*mlx).w, &(*mlx).h);
	(*mlx).gw.g[2] = mlx_xpm_file_to_image((*mlx).ptr, \
		"./spr/gr_2.xpm", &(*mlx).w, &(*mlx).h);
	(*mlx).gw.g[3] = mlx_xpm_file_to_image((*mlx).ptr, \
		"./spr/gr_3.xpm", &(*mlx).w, &(*mlx).h);
	(*mlx).gw.g[4] = mlx_xpm_file_to_image((*mlx).ptr, \
		"./spr/gr_4.xpm", &(*mlx).w, &(*mlx).h);
	(*mlx).gw.g[5] = mlx_xpm_file_to_image((*mlx).ptr, \
		"./spr/gr_5.xpm", &(*mlx).w, &(*mlx).h);
	(*mlx).gw.g[6] = mlx_xpm_file_to_image((*mlx).ptr, \
		"./spr/gr_6.xpm", &(*mlx).w, &(*mlx).h);
	(*mlx).gw.g[7] = mlx_xpm_file_to_image((*mlx).ptr, \
		"./spr/gr_7.xpm", &(*mlx).w, &(*mlx).h);
}

void	load_sprites_3(t_mlx *mlx)
{
	(*mlx).c.c = (void **)malloc(sizeof(void *) * (*mlx).c.wc);
	(*mlx).p.pl = (void **)malloc(sizeof(void *) * (*mlx).p.plc);
	(*mlx).c.c[0] = mlx_xpm_file_to_image((*mlx).ptr, \
		"./spr/C_0.xpm", &(*mlx).w, &(*mlx).h);
	(*mlx).c.c[1] = mlx_xpm_file_to_image((*mlx).ptr, \
		"./spr/C_1.xpm", &(*mlx).w, &(*mlx).h);
	(*mlx).c.c[2] = mlx_xpm_file_to_image((*mlx).ptr, \
		"./spr/C_2.xpm", &(*mlx).w, &(*mlx).h);
	(*mlx).p.pl[0] = mlx_xpm_file_to_image((*mlx).ptr, \
		"./spr/Pl_0.xpm", &(*mlx).w, &(*mlx).h);
	(*mlx).p.pl[1] = mlx_xpm_file_to_image((*mlx).ptr, \
		"./spr/Pl_1.xpm", &(*mlx).w, &(*mlx).h);
	(*mlx).p.pl[2] = mlx_xpm_file_to_image((*mlx).ptr, \
		"./spr/Pl_2.xpm", &(*mlx).w, &(*mlx).h);
	(*mlx).p.pl[3] = mlx_xpm_file_to_image((*mlx).ptr, \
		"./spr/Pl_3.xpm", &(*mlx).w, &(*mlx).h);
	(*mlx).p.pl[4] = mlx_xpm_file_to_image((*mlx).ptr, \
		"./spr/Pl_4.xpm", &(*mlx).w, &(*mlx).h);
	(*mlx).p.pl[5] = mlx_xpm_file_to_image((*mlx).ptr, \
		"./spr/Pl_5.xpm", &(*mlx).w, &(*mlx).h);
	(*mlx).p.pl[6] = mlx_xpm_file_to_image((*mlx).ptr, \
		"./spr/Pl_6.xpm", &(*mlx).w, &(*mlx).h);
	load_sprites_helper(mlx);
}
