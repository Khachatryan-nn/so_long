/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tikhacha <tikhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 18:18:10 by tikhacha          #+#    #+#             */
/*   Updated: 2023/05/08 09:24:41 by tikhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void static	mlx_put_player(t_mlx *mlx, t_point size, char **map)
{
	int	i;
	int	j;
	int	h;
	int	w;

	i = 0;
	w = 48;
	h = 48;
	while (++i < size.x)
	{
		j = 0;
		while (++j < size.y)
		{
			if (map[i][j] == 'P')
			{
				(*mlx).img.ptr = mlx_xpm_file_to_image((*mlx).ptr, "./sprites/P_1.xpm", &w, &h);
				mlx_put_image_to_window((*mlx).ptr, (*mlx).win, (*mlx).img.ptr, i * w, j * h);
				return ;
			}
		}
	}
}

void	mlx_start(t_mlx *mlx, t_point size, char **map)
{
	//int	width;
	//int	height;
	(void) map;

	//width = 48;
	//height = 48;
	(*mlx).ptr = mlx_init();
	(*mlx).win = mlx_new_window((*mlx).ptr, size.x * 48, size.y * 48, "so_long");
	mlx_put_player(mlx, size, map);
	mlx_put_coin(mlx, size, map);
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