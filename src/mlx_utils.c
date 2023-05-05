/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tikhacha <tikhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 18:18:10 by tikhacha          #+#    #+#             */
/*   Updated: 2023/05/05 19:12:24 by tikhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void static	mlx_put_player(t_mlx *mlx, t_point size, char **map)
{
	
}

void	mlx_start(t_mlx *mlx, t_point size, char **map)
{
	int	width;
	int	height;
	(void) map;

	width = 48;
	height = 48;
	(*mlx).mlx_ptr = mlx_init();
	mlx_put_player(mlx, size, map);
	(*mlx).mlx_win = mlx_new_window((*mlx).mlx_ptr, size.x * 48, size.y * 48, "so_long");
	(*mlx).img.img_ptr = mlx_xpm_file_to_image((*mlx).mlx_ptr, "/Users/tikhacha/Desktop/all/so_long/sprites/P_1.xpm", &width, &height);
	mlx_put_image_to_window((*mlx).mlx_ptr, (*mlx).mlx_win, (*mlx).img.img_ptr, 0, 0);
	(*mlx).img.img_ptr = mlx_xpm_file_to_image((*mlx).mlx_ptr, "/Users/tikhacha/Desktop/all/so_long/sprites/P_2.xpm", &width, &height);
	mlx_put_image_to_window((*mlx).mlx_ptr, (*mlx).mlx_win, (*mlx).img.img_ptr, 50, 50);
	(*mlx).img.img_ptr = mlx_xpm_file_to_image((*mlx).mlx_ptr, "/Users/tikhacha/Desktop/all/so_long/sprites/P_3.xpm", &width, &height);
	mlx_put_image_to_window((*mlx).mlx_ptr, (*mlx).mlx_win, (*mlx).img.img_ptr, 100, 100);
	(*mlx).img.img_ptr = mlx_xpm_file_to_image((*mlx).mlx_ptr, "/Users/tikhacha/Desktop/all/so_long/sprites/P_4.xpm", &width, &height);
	mlx_put_image_to_window((*mlx).mlx_ptr, (*mlx).mlx_win, (*mlx).img.img_ptr, 50, 0);
	(*mlx).img.img_ptr = mlx_xpm_file_to_image((*mlx).mlx_ptr, "/Users/tikhacha/Desktop/all/so_long/sprites/Ground.xpm", &width, &height);
	mlx_put_image_to_window((*mlx).mlx_ptr, (*mlx).mlx_win, (*mlx).img.img_ptr, 0, 50);
	if ((*mlx).img.img_ptr == NULL) {
    	printf("Error: Failed to load image file\n");
    	exit(1);
	}
	mlx_loop((*mlx).mlx_ptr);
}