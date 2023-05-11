/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tikhacha <tikhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 19:15:05 by tikhacha          #+#    #+#             */
/*   Updated: 2023/05/11 19:15:48 by tikhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	load_sprites(t_mlx *mlx)
{
	MLX.p.pfc = 4;
	MLX.p.prc = 8;
	MLX.p.pf = (void **)malloc(sizeof(void *) * MLX.p.pfc);
	MLX.p.pr = (void **)malloc(sizeof(void *) * MLX.p.prc);
	MLX.r.rvc = 4;
	MLX.r.rv = (void **)malloc(sizeof(void *) * MLX.r.rvc);
	if (!MLX.p.pf || !MLX.p.pr || !MLX.r.rv)
		exit(close_window(mlx));
	MLX.p.pf[0] = XPM(MLX.ptr, "./spr/P_1.xpm", &MLX.w, &MLX.h);
	MLX.p.pf[1] = XPM(MLX.ptr, "./spr/P_2.xpm", &MLX.w, &MLX.h);
	MLX.p.pf[2] = XPM(MLX.ptr, "./spr/P_3.xpm", &MLX.w, &MLX.h);
	MLX.p.pf[3] = XPM(MLX.ptr, "./spr/P_4.xpm", &MLX.w, &MLX.h);
	MLX.p.pr[0] = XPM(MLX.ptr, "./spr/Pr_0.xpm", &MLX.w, &MLX.h);
	MLX.p.pr[1] = XPM(MLX.ptr, "./spr/Pr_1.xpm", &MLX.w, &MLX.h);
	MLX.p.pr[2] = XPM(MLX.ptr, "./spr/Pr_2.xpm", &MLX.w, &MLX.h);
	MLX.p.pr[3] = XPM(MLX.ptr, "./spr/Pr_3.xpm", &MLX.w, &MLX.h);
	MLX.p.pr[4] = XPM(MLX.ptr, "./spr/Pr_4.xpm", &MLX.w, &MLX.h);
	MLX.p.pr[5] = XPM(MLX.ptr, "./spr/Pr_5.xpm", &MLX.w, &MLX.h);
	MLX.p.pr[6] = XPM(MLX.ptr, "./spr/Pr_6.xpm", &MLX.w, &MLX.h);
	MLX.p.pr[7] = XPM(MLX.ptr, "./spr/Pr_7.xpm", &MLX.w, &MLX.h);
	MLX.r.rv[0] = XPM(MLX.ptr, "./spr/Rv_0.xpm", &MLX.w, &MLX.h);
	MLX.r.rv[1] = XPM(MLX.ptr, "./spr/Rv_1.xpm", &MLX.w, &MLX.h);
	MLX.r.rv[2] = XPM(MLX.ptr, "./spr/Rv_2.xpm", &MLX.w, &MLX.h);
	MLX.r.rv[3] = XPM(MLX.ptr, "./spr/Rv_3.xpm", &MLX.w, &MLX.h);
}

void	load_sprites_2(t_mlx *mlx)
{
	MLX.gw.gc = 8;
	MLX.gw.wc = 2;
	MLX.d.dc = 5;
	MLX.gw.g = (void **)malloc(sizeof(void *) * MLX.gw.gc);
	MLX.gw.w = (void **)malloc(sizeof(void *) * MLX.gw.wc);
	MLX.d.d = (void **)malloc(sizeof(void *) * MLX.d.dc);
	if (!MLX.gw.g || !MLX.gw.w)
		exit(close_window(mlx));
	MLX.gw.w[0] = XPM(MLX.ptr, "./spr/w_0.xpm", &MLX.w, &MLX.h);
	MLX.gw.w[1] = XPM(MLX.ptr, "./spr/w_1.xpm", &MLX.w, &MLX.h);
	MLX.gw.g[0] = XPM(MLX.ptr, "./spr/gr_0.xpm", &MLX.w, &MLX.h);
	MLX.gw.g[1] = XPM(MLX.ptr, "./spr/gr_1.xpm", &MLX.w, &MLX.h);
	MLX.gw.g[2] = XPM(MLX.ptr, "./spr/gr_2.xpm", &MLX.w, &MLX.h);
	MLX.gw.g[3] = XPM(MLX.ptr, "./spr/gr_3.xpm", &MLX.w, &MLX.h);
	MLX.gw.g[4] = XPM(MLX.ptr, "./spr/gr_4.xpm", &MLX.w, &MLX.h);
	MLX.gw.g[5] = XPM(MLX.ptr, "./spr/gr_5.xpm", &MLX.w, &MLX.h);
	MLX.gw.g[6] = XPM(MLX.ptr, "./spr/gr_6.xpm", &MLX.w, &MLX.h);
	MLX.gw.g[7] = XPM(MLX.ptr, "./spr/gr_7.xpm", &MLX.w, &MLX.h);
	MLX.d.d[0] = XPM(MLX.ptr, "./spr/D_0.xpm", &MLX.w, &MLX.h);
	MLX.d.d[1] = XPM(MLX.ptr, "./spr/D_1.xpm", &MLX.w, &MLX.h);
	MLX.d.d[2] = XPM(MLX.ptr, "./spr/D_2.xpm", &MLX.w, &MLX.h);
	MLX.d.d[3] = XPM(MLX.ptr, "./spr/D_3.xpm", &MLX.w, &MLX.h);
	MLX.d.d[4] = XPM(MLX.ptr, "./spr/D_4.xpm", &MLX.w, &MLX.h);
	MLX.d.d[5] = XPM(MLX.ptr, "./spr/D_5.xpm", &MLX.w, &MLX.h);
}

void	load_sprites_3(t_mlx *mlx)
{
	MLX.c.wc = 3;
	MLX.c.c = (void **)malloc(sizeof(void *) * MLX.c.wc);
	if (!MLX.c.c)
		exit(close_window(mlx));
	MLX.c.c[0] = XPM(MLX.ptr, "./spr/C_0.xpm", &MLX.w, &MLX.h);
	MLX.c.c[1] = XPM(MLX.ptr, "./spr/C_1.xpm", &MLX.w, &MLX.h);
	MLX.c.c[2] = XPM(MLX.ptr, "./spr/C_2.xpm", &MLX.w, &MLX.h);
}
